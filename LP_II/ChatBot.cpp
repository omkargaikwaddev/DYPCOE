#include <iostream>      // For input and output
#include <string>        // For using string

using namespace std;

int main() {

    string userInput;   // Variable to store user message

    cout << "===================================" << endl;
    cout << "     CUSTOMER SUPPORT CHATBOT     " << endl;
    cout << "===================================" << endl;

    cout << "\nType 'exit' to end chat.\n" << endl;

    // Infinite loop for chatbot conversation
    while (true) {

        // Ask user for message
        cout << "You : ";

        // Take complete line input
        getline(cin, userInput);

        // If user types exit
        if (userInput == "exit") {

            cout << "Bot : Thank you for chatting!" << endl;

            // Exit loop
            break;
        }

        // Greeting response
        else if (userInput == "hello" ||
                 userInput == "hi") {

            cout << "Bot : Hello! How can I help you today?" << endl;
        }

        // Product inquiry response
        else if (userInput == "product") {

            cout << "Bot : We offer laptops, mobiles and accessories." << endl;
        }

        // Price inquiry response
        else if (userInput == "price") {

            cout << "Bot : Prices depend on the product model." << endl;
        }

        // Delivery inquiry response
        else if (userInput == "delivery") {

            cout << "Bot : Delivery usually takes 3 to 5 days." << endl;
        }

        // Payment inquiry response
        else if (userInput == "payment") {

            cout << "Bot : We accept UPI, cards and net banking." << endl;
        }

        // Help response
        else if (userInput == "help") {

            cout << "Bot : You can ask about product, price, payment or delivery." << endl;
        }

        // Unknown message response
        else {

            cout << "Bot : Sorry, I didn't understand that." << endl;
        }
    }

    return 0;   // End program
}

/*
Example Output
===================================
     CUSTOMER SUPPORT CHATBOT
===================================

Type 'exit' to end chat.

You : hello
Bot : Hello! How can I help you today?

You : product
Bot : We offer laptops, mobiles and accessories.

You : payment
Bot : We accept UPI, cards and net banking.

You : delivery
Bot : Delivery usually takes 3 to 5 days.

You : exit
Bot : Thank you for chatting!
*/

/*
Simple Explanation
What is a Chatbot?

A chatbot is a program that:

Talks with users
Gives automatic replies
Simulates human conversation
Working of this Chatbot

The chatbot:

Takes user input
Checks message using if-else
Gives suitable response
Features
Greeting support
Product inquiry
Payment inquiry
Delivery inquiry
Help option
Exit option
*/