/*TASK # 01: You are required to implement a simple message handling system using object-oriented programming in C++.
Task Breakdown:
*/

#include <iostream>
#include <string>
using namespace std;

/*1. Create a Message class
   o It should have a private instance variable text of type string to store the message content.
  o Implement a method toString() that returns the message text.
  o Provide a setter method to modify the text value.
*/

class Message {
    private:
    string text;

    public:
    Message() {
        text = "";
    }

    Message(string text) : text(text) {}

    void setText(string text) {
        this->text = text;
    }

    virtual string toString() {
        return text;
    }
};

/*2. Create an SMS class that inherits from Message
  o It should have an additional instance variable recipientContactNo to store the 
ecipient’s phone number.
  o Implement appropriate accessor and mutator methods.
  o Override the toString() method to return a concatenated string containing the 
recipient’s contact number and the message text.
*/

class SMS : public Message {
    private: 
    string recipientContactNo;

    public:
    SMS(string text, string recipientContactNo) : recipientContactNo(recipientContactNo), Message(text) {}

    void setRecipientContactNo (string recipientContactNo){
        this->recipientContactNo = recipientContactNo;
    }

    string getRecipientContactNo() const {
        return recipientContactNo;
    }

    string toString() override {
        return recipientContactNo + " " + Message::toString();
    }
};

/*3. Create an Email class that inherits from Message
  o It should have additional instance variables: sender, receiver, and subject.
  o Implement appropriate accessor and mutator methods.
  o Override the toString() method to return a concatenated string containing sender, 
eceiver, subject, and the message text.
*/

class Email : public Message {
    private:
    string sender;
    string receiver;
    string subject;

    public:
    Email(string text, string sender, string receiver, string subject) : Message(text), sender(sender), receiver(receiver), subject(subject) {}

    string getSender() const {
        return sender;
    }
    string getSubject() const {
        return subject;
    }
    string getReceiver() const {
        return receiver;
    }
    
    void setSender(string send) {
        sender = send;
    }
    
    void setSubject(string subj) {   
        subject = subj;
    }
    
    void setReceiver(string rec) {   
        receiver = rec;
    }
    
    string toString() override {
        return sender + " " + receiver + " " + subject + " " + Message::toString();
    }
};

/*4. Implement Keyword Search Function
  o Define a function:
    o bool ContainsKeyword(const Message& messageObject, const string& keyword);
    o This function should return true if the text of the Message object contains the given keyword, otherwise return false.*/

bool  ContainsKeyword(Message& messageObject, const string& keyword) {    
    size_t found = messageObject.toString().find(keyword);

    // If the keyword is found, return true; otherwise, return false
    return (found != string::npos);
}

/*5. Implement Message Encoding
  o Define a function to encode a given message using the following scheme:
   Each character should be replaced by the next character in the alphabet, e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
   Example: If the message is "This is Java", the encoded message should be 
Uijt jt Kbwb".*/

void EncodeMessage (string& messageObject) {    
    int size = messageObject.length(); 
    for (int i = 0; i < size; i++) {    
        if (messageObject.at(i) >= 'a' && messageObject.at(i) < 'z') {     
           messageObject.at(i)++;
         }   
         if (messageObject.at(i) >= 'A' && messageObject.at(i) < 'Z') {     
           messageObject.at(i)++;
         }
         if (messageObject.at(i) == 'z' || messageObject.at(i) == 'Z') {    
             messageObject.at(i) -= 25;
         }
    }
}


/*6. Test the Implementation
o In the main() function, create sample objects of SMS and Email, assign values, and test the functionalities including keyword search and encoding.*/

int main() {
    SMS msg1("Dear Customer, You have insuffiecent Balance", "033012344");
	Email msg2("Dear Student, Your exam is cancelled", "Teacher", "Student", "Exam details");
	cout << "msg1: " << msg1.toString() << endl;
	cout << "msg2: " << msg2.toString() << endl;

    cout << endl << "searching for keyword 'balance' " << endl;
	if (ContainsKeyword(msg1, "Balance")) {   
	    cout << "Keyword found in SMS" << endl;
	}
	else {    
	    cout << "Keyword not found in SMS" << endl;
	}
	cout << endl;

    cout << "searching for keyword 'Hello' " << endl;
	if (ContainsKeyword(msg2, "Hello")) {   
	    cout << "Keyword found in Email" << endl;
	}
	else {    
	    cout << "Keyword not found in Email" << endl;
	}
	cout << endl;

    string str;
    str = msg1.toString();
    EncodeMessage(str);
    cout << "encoded msg1: " << str << endl;

    str = msg2.toString();
    EncodeMessage(str);
    cout << "encoded msg2: " << str << endl;
}