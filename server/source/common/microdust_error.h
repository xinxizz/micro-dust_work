//����˴��������
#define MDJSS_BASE_ERR                    0x000000000

//����
#define MDJSS_TASK_BASE_ERR               (MDJSS_BASE_ERR + 0x1000)
#define MDJSS_TASK_UNINIT_ERR             (MDJSS_TASK_BASE_ERR + 0x1)//δ��ʼ��
#define MDJSS_TASK_REQUEST_FORMAT_ERR     (MDJSS_TASK_BASE_ERR + 0x2)//�����ʽ����

//��Ϣ����
#define MDJSS_MSG_BASE_ERR                (MDJSS_BASE_ERR + 0x2000)
#define MDJSS_MSG_NO_PROCESSOR_ERR        (MDJSS_MSG_BASE_ERR + 0x1) 
