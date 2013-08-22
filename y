be62379 seesaw3 conf cancell
afd625f back running
fe249bd can uprun to thw seesaw
05ed2a3 remove hoge.txt
013ebb1 added hoge.txt
84ae8c5 test backward
6145ea3 adjust PID parameter and added validate func on SpeedEncoder
efd965d change type integer to float on SpeedEncoder
b3d4cff imple InclinationSwitch
147da10 後退時でも旋回量の計算が正しく行われるように修正曲率制御
baecf6f 後退時でも旋回量の計算が正しく行われるように修正輝度制御
540510a update DistanceSwitch
9b164dc remove SeesawFactory
d0072fe rewrite Factories using constructor
84fded5 後退をテテスト
4143107 adjust PID paramter for speed Control
470d80a change factory
d53c40e added rapid speed Up func
402f5bf added Stop Function
2d225d9 remove Inlude stdlib because of data size
cc3a212 remove SecondCurve_3Factory
5dfb1b8 added Function call of secondCurve_init()
f4c0db4 remove StartedRunningFactory instead of StartUpFactory
717a67c added Section info until Second Curve
6018ff9 imple StartUp Section
6198100 change the way of holding object for PIDSpeedCtrl
7b7237b modified Kido PID parameters
1df30dd change targetValue
53ae1ed added EXCEL FILE
83a6010 Merge branch 'BTParam'
faaf03e Merge branch 'master' of github.com:class-snct-rikitakelab/Strange-lovers
f3ff1a1 test some bugs
f31162e モデルシート参考資料アップロード
74050a9 test section update
f1c002b remove the bug of unstable startup running
5d6a2f1 implement display float value use ecrobot_debug1
015249b modified model around UI Package
7bf7450 modified model on 0813 for taking corespond to source and model around lightvalCtrl
77db083 tested ParameterReceiver Class
762739f change the way to keep Parameter Object on LightValControl Package
01c457a remove paramter use LVE cuz not necessaraly
19d5d0e remove TargetValue Class
005b927 remove extra member variations on PIDLightValCtrl
f72843f imple Parameter Receve Class but something go wrong arround object links
272f1fb fake imple done
c1ea128 implement paramterReceive Class but not tested
79a851c added fake imple
868e21f added ParameterReciver_init funct
b3a9cce added Paramter Reciver Class skelton
7da3b64 added constractor of Section class and RunningMethod Class
4ba1ac6 fix conflict
0884b48 remove comment outs and refactroing INITILIZE TASK
b66ebc9 remove comment out
4c579eb remove comment out
11c6002 replace Display.c and .h
2ab5f62 added restart func comp
5d90ae6 merge seesaw
6641b01 StartedRunning
e7a765c not comp
ba6055e fixed conflict
ee4b933 TASK is dead
185ca87 added restart func
b06574b Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seesaw
fb63874 toriaezu kennti dekita
b2a594d Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seesaw
a23fa76 added speed switch term
8dd4ac5 test
666e45d test
a413ae9 chinatsu?1
6af5ca5 chinatsu
23960c6 add speed and timer switch function
b6c60ef test2
4e0a36b Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seesaw
ba54ac7 test
5fedd79 make time reset
1473669 SpeedTimerMultipleSwitch
ab993dc te
407e7c4 1
e2ec36b added spd time switch
b9a8026 Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seesaw
bb6a7f0 fix conf
ffb1931 remove compile error
873faf1 add array initialize on MovingAverage_init
1b4c4d7 remove all static members except for calibration class
0083988 remove PID_Brightness
ca4b32f remove static members
9dfd6ad fix conf
da21be2 Merge branch 'seasaw' into seesaw
b677a04 added Multimple Switch with timer and speed but not implemented
2a345ac added Multimple Switch with timer and speed but not implemented
888de13 seesawnodansahantei
7573720 Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seasaw
ebc5e40 remove PID_brihtness
34a54af update PID
f8d4e51 20130805
4a8c4bb no ci
8ad7167 tekito- parameter
eb351d9 dekito- paramater
e8e309c Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seesaw
648e88c default Running Method
0689d02 Merge branch 'seesaw' of github.com:class-snct-rikitakelab/Strange-lovers into seesaw
a9ca17b no comp
4b85424 change parameters
dcbd7f0 added First curve and Slope info
d3093f5 implementedd LowPassFilter
21a6d65 added LPF class
5012a43 added model
6862f28 added new model 0803_v2
77ea706 fix conflict on Strategy Factory
a2ced71 fix confilic
b9696e3 compleat target light value
872a640 add target brightness model
c6fdb94 done Curvature Ctrl
2eba14f adjust Curvature PID paramters
284190c change Encoder call cycle
021457c remove speed Control bugs
07fe0f7 change model corresponds to WheelActuator
ab6ff10 change balance class into WheelActuator
bf3e8f6 added MovingAverage into lib folder
e9cb541 add model
61f9580 add CtrllightValue
34f018f not complete 0731
80d635c testing
8c42bf4 added SeeSaw Section
0d0ca87 remove SpeedContro Package errors
3215a0a fix bugs on Section Switching
ccabad4 added model in Japanese
df95126 added seaquence diagram
29c45b4 change sequence of Section_run but not pass test yet
e744780 trying section change
71e988b modified model
7f3a4ac remove bugs on Runner_init()
95ac1ea added firstStraightObject and methods
7665517 imple Section_run method
7062024 change algo and interface in StrategyPackage
8b00f26 imple SiwtchJudge Class using function pointer
c872b3c modified model
cb9a8bd change Runner_run function
ed6cb69 remove some files
b555415 move Runner
cdaa820 imple RunningMethod_execute_method func
4bcccaf rename file name from ControllerWegiht to ContrllerWight
98d9b0c modified requestDrive func interface and imple RunningMethod
17eaa81 imple Section Class
5028d8b imple strategy
1517fe4 added first paraters for own object
e9b1f4a added Strategy Part Skelton
1368506 change parameters name on model
1b8902a change connection around DrivenDrictor and Runenr
b7321c1 change attribute name angle_of_aim to target_tail_angle
37ed261 delete model 20130725
73c8857 added models In English for Section
9142991 added models and change some paramaters of brightness PID
9ae1562 added model_2013_0725 for Senction idea
f496188 modified model
b3100d5 done refactring like model catlog on Curvature Control
898e177 remove comment out
31645cb remove declear isntaces of TargetLightVaControl system for removing build error
cf35ca7 replaced curvatureCalc
a87d2ca delete xlsfiles
e83c792 added survey result of curvatureEncoder
dd99d58 modified CurvatureEncoder
447c90a add control brightness
c978acb Merge branch 'master' into surver4CurvatureEncodere
6849c10 change logSend Function
3f945d0 check CurvatureEncoder logic
8142e71 Merge branch 'master' of github.com:class-snct-rikitakelab/Strange-lovers
105c3ba right control
f8a2ff9 strenge lovers_astah hiromitsuEdit
8f8b059 added strenge_lovers_hiromitsuEdit
3c635d7 fininsh implementing DrivenDirector Class
6232616 imple DrivenDirector Class
bc10814 added DrivenDirector Class skelton
940ed7a remove extra words on PID_Brightness class
b262eed implemented CurvatureEncodeer
e32dc69 added CurvatureEncoder class kelton
8b030bd change target control system from DirectionControl to CurvatureControl
878e9fe modifeid model
685697c added fake implementation of Direction PID Control. need to be refactored
b17a1e9 added DirectioCtrl Class skelton
32c146f rename package name of SpeedTargetControl to TargetSpeedControl
1f45e6a implemented DirectionEncoder Class
24e7618 added DirectionEncoder class skelton
4a0145d modified model
d7fa6f2 added strenge_lover_20120720_v2.asta
7dad00c change target value for review
d02256c complete speedControl
1a8d9b6 implement speedControl like Model Catalog
90bdc73 modified model for using speedControl
688e633 Nmura SpeedControl Classes but not using yet
fff1200 change connections using BrightnessEncoder Class
f0856f3 added BrightnessEncoder Class
8287ad1 added LightSensor class
7ada959 change connection using Tail Motor class from PID_Tail Class
f6f4d32 added TailMotor Class
60be3c8 remove cashes of class
6fac768 replace class to be in DrivenPart
b44ba5d added DrivenPart Package in the model
1e93e51 added separete calibration version model on class diagram
d7a8be0 modified astah file 20130719
b803c16 remove balancer method for no paraters
0799a45 implemented Inclination Encoder class
a2018be added Inclination class skelton
d702c33 added GyroSensor Class in Hardwre Wrapper Package
9548ad3 added model_impl
2328d2b move astah file to models folder
35cc93d fix conflict on Runner.c using evet
395adf3 Cleaned Runnner
1734f18 remove bugs on SpeedEncoder Class
630ce63 removing task error
32c46ed imple SpeedEncoder but Still there are bugs
083d67a Merge branch 'master' of github.com:class-snct-rikitakelab/Strange-lovers
68fab5e add init task
5a5a5fc modified Speed Encoder Class skelton
fc4319a Merge branch 'implement_timer'
094decd implemted DistanceEncoder
94aaf03 struct is done
23dae70 added Distance Encoder Class skelton
6ae2a26 implemented Timer class
c950ca0 added astah file
c170e66 added Timer skelton
22ff74a implemented Wheel motor
fa4ef4d added WheelMotor class skelton
e71758a added Motor skeltn
ac040fd added HardwareWrapper package
2b5885a remove all compile error
77da6a6 remove connection between PID_tail Class and Target_Value class to use paramter on pit tail control method
a61bd73 chage display method interface using parameters
5a2c4d4 to use arrow operator instated of . operator on calibration method
624d6fa change interface of Calibaration_calibration method
f5b5c1b remove warnings by end of file
e30263c remove sytax errros
2a2d703 Panaino
3793fe7 Merge branch 'master' of github.com:class-snct-rikitakelab/Strange-lovers
2dfa13c adding more
a783fa1 added images of class diagram
f319557 Merge branch 'master' of github.com:class-snct-rikitakelab/Strange-lovers
b18677e tail to start is compleat
aaefbd1 change .gitignore
93bce48 remove asta files on root directory
8a8370b move asth files to models
64956aa Merge branch 'master' of github.com:class-snct-rikitakelab/Strange-lovers
8c54db3 commit speed model
31ad1a0 line tracking is succsess
3f7464a speed controll
d20b04a add tail model
1c6a1b0 display gyro
01b5201 add tail control
bd45a4f asta ate...
56e914a vcxproj.filters is dead
6f4482c add filters
b2fc61a first commit
cdf00aa modified .gitignore to manage only sorce code
78847ed ignore
