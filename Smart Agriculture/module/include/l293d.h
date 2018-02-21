

#define L293D_MASK 			(1<<30)|(1<<29)|(1<<28)|(1<<27)
#define L293D_FORWARD() (1<<29)|(1<<27)
#define L293D_BACK() 		(1<<30)|(1<<28)
#define L293D_LEFT() 		(1<<27)
#define L293D_RIGHT()		(1<<29)
typedef enum{
	
	FORWARD,BACKWARD,LEFT_TURN,RIGHT_TURN
}motor_dir_t;

void L293D_Motor_Control(motor_dir_t _motor_option);
void Init_L293D(void);
