#include "SeeSaw_1Factory.h"


void seesaw_1_factory_init(){
	ControllerWeight use_controller;
	SwitchTerm switch_term;
	int balancing_requrement =0;
	int target_tail_angle=0;
	int gyroOffsetRevise=0;
	int request_forced_stop;
	MovementDirection movementDirection = FORWARD;
	int (*fp_SwitchJudge)(SwitchTerm);

	use_controller.target_curvature_controller_weight =0.0; //�ȗ�����̏d�ݕt��
	use_controller.target_light_controller_weight =1.0;	//�P�x����̏d�ݕt��
	switch_term.distance = 500; //�����ؑւ��̗p�����ۂ̐ؑ֏��� [mm]
	switch_term.inclination = 0; //�X���ؑւ��̗p�����ۂ̐ؑ֏���
	switch_term.speed = 50; //���x�ؑ֏��� [mm/s]
	switch_term.time =5000; //���Ԑؑ֏��� [ms]
	balancing_requrement = 0; //�|������̗L�� 1:�|�����s 0:�K�����s ���킹�ĐK���p�x���X�T�x���x�ɂ���K�v����
	target_tail_angle=100; //�K���̖ڕW�p�x
	gyroOffsetRevise=0; //�W���C���I�t�Z�b�g�ύX�ʁ@+�����ɑ��₷�Ƌ}���� -�����ɑ��₷�Ƌ}�����@���������Z���`���x�i�񂾒i�K�ŃI�t�Z�b�g��߂��Ȃ��ƃo�����X������ē]�|����
	request_forced_stop= 0; //���S�ɒ�~�������ꍇ��1 �ʏ�̐�����|����ꍇ��0
	movementDirection = FORWARD; //�i�s�����ɏ]���Đݒ肷��@�O�i FORWARD ���BACKWARD
	fp_SwitchJudge = SpeedTimerMultipleSwitch_judge_switch_method; //�ؑւ𔻒肷��֐������w��@
	/*
	�����ؑ� DistanceSwitch_judge_switch_method
	���Ԑؑ� TimeSwitch_judge_switch_method
	�Ȃ�
	*/

	RunningMethod_init(&SeesawFirstLineTraceMethod,balancing_requrement,use_controller,target_tail_angle, gyroOffsetRevise,switch_term,fp_SwitchJudge,request_forced_stop,movementDirection);


	seesaw_1_running_method_array[0]=SeesawFirstLineTraceMethod; //���{���鑖�@��z�񏇔ԂɊi�[

	int number_of_running_method=1; //��ԂŎ��{���鑖�@�̌�
	TargetValues target_values;  
	target_values.target_brightness = 0.5; //�ڕW�P�x
	target_values.target_curvature = 0.0; //�ڕW�ȗ� [1/mm]
	target_values.target_speed = 100;  //�ڕW���x [mm/s]
	Section *nextSection = &seesaw_stop; //���̋��
	RunningMethod *runningMethod = seesaw_1_running_method_array;
	Section_init(&seesaw_1,nextSection,number_of_running_method,runningMethod,target_values);
}
