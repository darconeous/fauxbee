

#include <contiki.h>
#include <smcp/smcp.h>
#include <smcp/observe.h>
#include "pin.h"

smcp_status_t
pin_request_handler(void* context) {
	uint8_t i;

	if(smcp_inbound_get_code() != COAP_METHOD_GET) {
		return SMCP_STATUS_NOT_IMPLEMENTED;
	}

	while(smcp_inbound_peek_option(NULL, NULL) != COAP_OPTION_URI_PATH)
		if(smcp_inbound_next_option(NULL, NULL) == COAP_OPTION_INVALID)
			break;

	for(i=0;i<pin_count();i++) {
		if(!pin_mode_get(i))
			continue;

		if(!smcp_inbound_option_strequal(COAP_OPTION_URI_PATH,pin_localname_get(i)))
			continue;


	}

	if(smcp_inbound_option_strequal(COAP_OPTION_URI_PATH, "hello-world")) {

		smcp_outbound_begin_response(COAP_RESULT_205_CONTENT);

		smcp_outbound_add_option_uint(
			COAP_OPTION_CONTENT_TYPE,
			COAP_CONTENT_TYPE_TEXT_PLAIN
		);

		smcp_outbound_append_content("Hello world!", SMCP_CSTR_LEN);

		return smcp_outbound_send();
	}

	return SMCP_STATUS_NOT_FOUND;
}

