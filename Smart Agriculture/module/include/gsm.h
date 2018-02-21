

#ifndef _GSM_H
#define _GSM_H


void SMS_Send(char* sms_to, char *gsm_message);
char Init_GSM(void);
char Rxd_GSM(void);
char get_GSMMotorControlStatus(void);
void GSM_ClearControlFlag(void);
char GSM_Command(char *command);


#endif 





