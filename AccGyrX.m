AccGyr = readtable("C:\Users\HUB4RT\Desktop\WorkStuff\Python\accel-gyro\AccelGyroData.csv");

% removes time which is unnecessary data from logger
AccGyr(:,1) = []; 

AccGyr.Properties.VariableNames  = {'t','Ax','Ay','Az', 'Gx', 'Gy', 'Gz'};

AccGyrTT = table2timetable(AccGyr, 'RowTimes', seconds(AccGyr.t));
%Simulink
Period = 0.02; % Done in 100 HZ sampling

AccGyrTT = retime(AccGyrTT, 'regular', 'linear', 'TimeStep', seconds(Period));

figure; 
plot(seconds(AccGyrTT.Time), [AccGyrTT.Ax], 'Color', "r"); 
grid on; 
xlabel('Time Elapsed (s)'), ylabel('Raw Data');
title('Accelerometer (Ax)');
legend('Ax');

figure; 
plot(seconds(AccGyrTT.Time), [AccGyrTT.Ay], 'Color', "g"); 
grid on; 
xlabel('Time Elapsed (s)'), ylabel('Raw Data');
title('Accelerometer (Ay)');
legend('Ay');

figure; 
plot(seconds(AccGyrTT.Time), [AccGyrTT.Az], 'Color', "b"); 
grid on; 
xlabel('Time Elapsed (s)'), ylabel('Raw Data');
title('Accelerometer (Az)');
legend('Az');

figure; 
plot(seconds(AccGyrTT.Time), [AccGyrTT.Gx], 'Color', "r"); 
grid on; 
xlabel('Time Elapsed (s)'), ylabel('Raw Data');
title('Gyroscope (Gx)');
legend('Gx');

figure;  
plot(seconds(AccGyrTT.Time), [AccGyrTT.Gy], 'Color', "g"); 
grid on; 
xlabel('Time Elapsed (s)'), ylabel('Raw Data');
title('Gyroscope (Gy)');
legend('Gy');

figure; 
plot(seconds(AccGyrTT.Time), [AccGyrTT.Gz], 'Color', "b"); 
grid on; 
xlabel('Time Elapsed (s)'), ylabel('Raw Data');
title('Gyroscope (Gz)');
legend('Gz');

% Convert to timeseries for Simulink
t = seconds(AccGyrTT.Time);   % shared time vector

% Accelerometer
AccX = timeseries(AccGyrTT.Ax, t);
AccY = timeseries(AccGyrTT.Ay, t);
AccZ = timeseries(AccGyrTT.Az, t);
GyrX = timeseries(AccGyrTT.Gx, t);
GyrY = timeseries(AccGyrTT.Gy, t);
GyrZ = timeseries(AccGyrTT.Gz, t);

%Acc = [AccX.Data AccY.Data AccZ.Data];
%Gyr = [GyrX.Data GyrY.Data GyrZ.Data];

save imu_for_simulink.mat AccX AccY AccZ GyrX GyrY GyrZ