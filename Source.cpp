#include "sleepy_discord/sleepy_discord.h"
#include "sleepy_discord/websocketpp_websocket.h"

class DSClient : public SleepyDiscord::DiscordClient {
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    void onMessage(SleepyDiscord::Message message) {
        if (message.startsWith("hello"))
            sendMessage(message.channelID, "Hello " + message.author.username);
    }
};

int main() {
    DSClient client("very secret info (token)", 2);
    client.run();
}