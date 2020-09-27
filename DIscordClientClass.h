#include "sleepy_discord/sleepy_discord.h"
#include "sleepy_discord/websocketpp_websocket.h"

#include "UserCommand.h"
#include <map>
#include "player.h"
#include <string>

class DSClient : public SleepyDiscord::DiscordClient {
private:
    std::map<std::string, player> playerlist;
public:
    using SleepyDiscord::DiscordClient::DiscordClient;
    /*void onMessage(SleepyDiscord::Message message) {
        if (message.startsWith("hello"))
            sendMessage(message.channelID, "Hello " + message.author.username);
    }*/
    void onMessage(SleepyDiscord::Message message) {
        UserCommand command;
        if (message.startsWith("+sa")) {
            command.make_command(message.content);
            run_command(command);
        }
    }
};

void run_command(UserCommand command) {

}