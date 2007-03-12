#include <monapi.h>
#include <monalibc.h>
#include <servers/audio.h>
#include "../debug.h"

using namespace MonAPI;

int main(int argc, char *argv[])
{
	uint32_t audioServerID;
	int32_t ch;
	MessageInfo msg;

	audioServerID = Message::lookupMainThread("AUDIO.EX5");
	if( audioServerID == THREAD_UNKNOWN )
		exit(printf("Couldn't find an audio server."));
	dprintf("AUDIO.EX5 : %x\n", audioServerID);
	Message::sendReceive(&msg, audioServerID, MSG_AUDIO_SERVER_COMMAND, GetServerVersion);
	_printf("Server version: %x:%x\n", msg.arg2, msg.arg3);
	Message::sendReceive(&msg, audioServerID, MSG_AUDIO_SERVER_COMMAND, AllocateChannel);
	ch = msg.arg2;
	_printf("Channel: %d\n", ch);
	msg.arg1 = ch;
	msg.arg2 = 44100;
	msg.arg3 = 16;
	Message::sendReceive(&msg, audioServerID, MSG_AUDIO_SERVER_COMMAND, PrepareChannel);
	_printf("Result: %d\n", msg.arg2);
	msg.arg1 = ch;
	Message::sendReceive(&msg, audioServerID, MSG_AUDIO_SERVER_COMMAND, ReleaseChannel);
	_printf("Channel was released.\n");

	return 0;
}

