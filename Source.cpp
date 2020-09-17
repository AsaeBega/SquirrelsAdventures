#include "sleepy_discord/sleepy_discord.h"
#include "sleepy_discord/websocketpp_websocket.h"

class myClientClass : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) {
        if (message.startsWith("whcg hello"))
            sendMessage(message.channelID, "Hello " + message.author.username);
    }
};

int main() {
    myClientClass client("NzQzNDkyMTQ3ODg5ODMxOTg4.XzVdBQ.XE2_HcSqYcOyvfdIygJtnJvg30E", 2);
    client.run();
}