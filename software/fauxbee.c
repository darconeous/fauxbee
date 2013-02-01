#include <contiki.h>
#include "net/resolv.h"

#include <smcp/smcp.h>
#include "led-node.h"
#include "sensor-node.h"
#include "smcp-task.h"

PROCESS_NAME(fauxbee_main);
PROCESS(fauxbee_main, "fauxbee");

AUTOSTART_PROCESSES(
	&resolv_process,
	&smcp_task,
	&fauxbee_main,
	NULL
);

//////////////////////////////////
// MAIN THREAD

PROCESS_THREAD(fauxbee_main, ev, data)
{
	PROCESS_BEGIN();

	smcp_init_led_node(smcp_get_root_node(smcp),"leds");

#if !CONTIKI_TARGET_MINIMAL_NET
	smcp_init_sensor_node(smcp_get_root_node(smcp),"sensors");
#endif

	PROCESS_END();
}
