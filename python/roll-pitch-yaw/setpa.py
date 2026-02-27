import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv

ser = serial.Serial(port="COM14", baudrate="115200", timeout=0.02)

# # ---------------------------- CSV SETUP ----------------------------
csv_AccelGyroData = "AccelGyroData.csv"
csv_file_AccelGyroData = open(csv_AccelGyroData, "w", newline="")   # overwrite each run; use "a" to append
csv_writer_AccelGyroData = csv.writer(csv_file_AccelGyroData)
csv_writer_AccelGyroData.writerow(["Sample", "seconds_elapsed", "Acx", "Acy", "Acz", "Gyx", "Gyy", "Gyz"])
csv_file_AccelGyroData.flush()

#################################### FUNCTION ####################################

def parse_line(line, reset):
    d = {}
    for part in line.split(","): #"Agx:0.12,Agy:-0.03,Agz:1.01\r\n"
        #print(part)
        if ":" not in part:
            continue
        k, v = part.split(":", 1)
        #print(k)
        #print(v)
        k = k.strip()
        #print(k)
        v = v.strip()
        #print(v)
        try:
            d[k] = float(v)
            # reset = 0
            # print("Good")
        except ValueError:
            # reset = 1
            # print("Error")
            continue
        #print(d[k])
    return d, reset

def autoscale(ax, y, pad=0.15, min_span=1e-3):
    """Autoscale ax y-limits to data y with padding."""
    if not y:
        return
    y_min = min(y)
    y_max = max(y)
    span = y_max - y_min
    if span < min_span:
        mid = 0.5 * (y_min + y_max)
        span = 1.0
        y_min, y_max = mid - 0.5 * span, mid + 0.5 * span
    else:
        y_min -= pad * span
        y_max += pad * span
    ax.set_ylim(y_min, y_max)

#################################### FUNCTION ###################################
x = []
agx = []
agy = []
agz = []
gyx = []
gyy = []
gyz = []
t_v = []
sample = 0
i = 0
N = 1000

fig_a, axs = plt.subplots(6, 1, sharex=True, figsize=(9, 7))
fig_a.suptitle("Live Acceleration & Gyro")

labels_a = ["Roll", "Pitch", "Yaw", "AngX", "AngY", "AngZ"]
colours_a = ["tab:red", "tab:green", "tab:blue", "tab:red", "tab:green", "tab:blue"]
lines_a = []
for ax, lab, col in zip(axs, labels_a, colours_a):
    ln, = ax.plot([], [], color=col, linewidth=2.0)
    ax.set_ylabel(lab)
    ax.grid()
    lines_a.append(ln)
axs[-1].set_xlabel("Sample #")

FLUSH_EVERY = 10
_rows_since_flush = 0

def update(_):
    global sample, _rows_since_flush, reset
    reset = 0

    # Read everything available right now
    while ser.in_waiting:
        raw = ser.readline()
        if not raw:
            break

        s = raw.decode("utf-8", errors="ignore").strip()
        #print(s)
        if(s == 'FFFFFFFF'):
            csv_file_AccelGyroData.flush()
            _rows_since_flush = 0
            sample = 0
        
        if not s:
            continue

        d, reset = parse_line(s, reset)
        a1 = d.get("Roll")
        a2 = d.get("Pitch")
        a3 = d.get("Yaw")
        a4 = d.get("AngX")
        a5 = d.get("AngY")
        a6 = d.get("AngZ")
        t_val = d.get("Time")
        if a1 is None or a2 is None or a3 is None or a4 is None or a5 is None or a6 is None:
            continue

        x.append(sample)
        agx.append(a1)
        agy.append(a2)
        agz.append(a3)
        gyx.append(a4)
        gyy.append(a5)
        gyz.append(a6)
        t_v.append(t_val)

    ############################# CSV #############################
        # ---- write to CSV (updates continuously) ----
        csv_writer_AccelGyroData.writerow([sample, t_val, a1, a2, a3, a4, a5, a6])
        _rows_since_flush += 1
        if _rows_since_flush >= FLUSH_EVERY:
            csv_file_AccelGyroData.flush()
            _rows_since_flush = 0
            continue
        if (reset == 1):
            csv_file_AccelGyroData.flush()
            _rows_since_flush = 0
            sample = 0
            reset = 0
            continue
        # if (sample > 1000):
        #     csv_file_AccelGyroData.flush()
        #     csv_file_AccelGyroData.close()
        #     ser.close()
    ############################# END #############################
        sample += 1
        print(sample, reset)
    if len(x) > N:
        del x[:-N]
        del t_v[:-N]
        del agx[:-N]
        del agy[:-N]
        del agz[:-N]
        del gyx[:-N]
        del gyy[:-N]
        del gyz[:-N]

    lines_a[0].set_data(t_v, agx)
    lines_a[1].set_data(t_v, agy)
    lines_a[2].set_data(t_v, agz)
    lines_a[3].set_data(t_v, gyx)
    lines_a[4].set_data(t_v, gyy)
    lines_a[5].set_data(t_v, gyz)
    
    # Auto y-scale each subplot based on last N samples
    autoscale(axs[0], agx, pad=0.15)
    autoscale(axs[1], agy, pad=0.15)
    autoscale(axs[2], agz, pad=0.15)
    autoscale(axs[3], gyx, pad=0.15)
    autoscale(axs[4], gyy, pad=0.15)
    autoscale(axs[5], gyz, pad=0.15)
    #print(agx, agy, agz)

    axs[-1].set_xlim(t_v[0], t_v[-1])
    return lines_a

ani_a = FuncAnimation(fig_a, update, interval=30, blit=False)
try:
    plt.show()
finally:
    csv_file_AccelGyroData.flush()
    csv_file_AccelGyroData.close()
    ser.close()