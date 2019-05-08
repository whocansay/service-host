
#include <stdint.h>

#define SERVICE_START_AUTO	0x00 // start only on operation request to save memory
#define SERVICE_START_STARTUP	0x01 // start and stop when host does

#define SERVICE_STATUS_STOPPED	0x00
#define SERVICE_STATUS_STARTED	0x01
#define SERVICE_STATUS_PAUSED	0x03
#define SERVICE_STATUS_RUNNING	0x04
#define SERVICE_STATUS_DISABLED	0x05

typedef struct service
{
	uint32_t id; // crc32 of service name
	uint8_t startType;
	uint8_t status;
	void *module_handle;
	void *thread_handle;
	void *input;
	void *output;
} *service_t;

service_t service_register(const char *name, void *module_handle);
int service_unregister(service_t);
int service_start(service_t);
int service_stop(service_t);
int service_pause(service_t);
int service_resume(service_t);
service_t service_lookup(const char *name);
