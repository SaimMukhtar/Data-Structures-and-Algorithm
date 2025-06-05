//Saim Mukhtar
//22i-1415
//Assignment 1 (AI-A)

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Message {
private:
    int timestamp;
    string sender_id;
    string message_content;

public:
    Message(int ts, const string& sid, const string& content) : timestamp(ts), sender_id(sid), message_content(content) {}

    int getTimestamp() const {
        return timestamp;
    }

    string getSenderID() const {
        return sender_id;
    }

    string getMessageContent() const {
        return message_content;
    }
};

class MessageQueue {
private:
    queue<Message> messages;

public:
    void sendMessage(const string& sender_id, const string& message_content, int timestamp) {
        messages.push(Message(timestamp, sender_id, message_content));
    }

    Message receiveMessage() {
        if (messages.empty()) {
            cout << "No messages in the queue." << endl;
            return Message(0, "", "");
        }
        Message msg = messages.front();
        messages.pop();
        return msg;
    }

    void displayMessages() {
        if (messages.empty()) {
            cout << "No messages in the queue." << endl;
            return;
        }
        queue<Message> temp = messages;
        while (!temp.empty()) {
            Message msg = temp.front();
            cout << "Timestamp: " << msg.getTimestamp() << ", Sender ID: " << msg.getSenderID() << ", Message: " << msg.getMessageContent() << endl;
            temp.pop();
        }
    }
};

int main() {
    MessageQueue messageQueue;

    // User A sends three messages
    messageQueue.sendMessage("User A", "Message 1 from User A", 5);
    messageQueue.sendMessage("User A", "Message 2 from User A", 3);
    messageQueue.sendMessage("User A", "Message 3 from User A", 7);

    // User B sends two messages
    messageQueue.sendMessage("User B", "Message 1 from User B", 4);
    messageQueue.sendMessage("User B", "Message 2 from User B", 6);

    // Display messages in the correct order
    cout << "Messages received in the application:" << endl;
    messageQueue.displayMessages();

    return 0;
}
