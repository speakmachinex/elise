#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void quit(char *response) {
    // There has to be a more elegant way of doing this?
    if (strcmp(response, "bye") == 0) { exit(0); }
    if (strcmp(response, "goodbye") == 0) { exit(0); }
    if (strcmp(response, "quit") == 0) { exit(0); }
    if (strcmp(response, "exit") == 0) { exit(0); }
    if (strcmp(response, "cya") == 0) { exit(0); }
}

void lowercase(char *response, char *input) {

    for (int i = 0; i < strlen(response); i++) {
        response[i] = tolower(response[i]);
    }
    strcpy(input, response);
}

int main(void) {

    char response[50];
    char *input;

    int said_hello = 0;

    printf("Welcome to\n");
    printf("                                   \n");
    printf("███████╗██╗     ██╗███████╗███████╗\n");
    printf("██╔════╝██║     ██║██╔════╝██╔════╝\n");
    printf("█████╗  ██║     ██║███████╗█████╗  \n");
    printf("██╔══╝  ██║     ██║╚════██║██╔══╝  \n");
    printf("███████╗███████╗██║███████║███████╗\n");
    printf("╚══════╝╚══════╝╚═╝╚══════╝╚══════╝\n");
    printf("                                   \n");

    printf("Hi! I'm Elise. What seems to be your boggle?\n");

    while (1) {

        printf("> ");
        scanf("%s", response);
        lowercase(response, input);
        // printf("You said %s\n", input);
        quit(input);

        if (strstr(input, "hello") != NULL) {
            switch (said_hello) {
                case 0: printf("Hello. How can I help?\n"); break;
                case 1: printf("We've already said hello. How can I help?\n"); break;
                case 2: printf("It is generally considered rude to say hello many times.\n"); break;
                // case 3: printf("Goodbye"); exit(0);
                default: printf("Let's change the subject.\n"); break;
            }

            said_hello++;
        }

    }

    // Strip punctuation: .,;!?()

    // If "Hello" is mentioned, reply back. Count "hellos". If used more than once
    // acknowledge this, and try to move the conversation along

    // Use pre-defined responses, sometimes incorporating the user input
    // When incorporating user input, translate terms such as "I" to "You"
    // Eg. If a user says "I'm feeling depressed" -> "Why do you believe/feel/think you are depressed?
    // If emotional term is used in combination with I, ask why "emotional term".
    // How long have you been feeling "emotional term"

    // Emotional language that describes a person or a group
    // "Men are all" alike/the same
    // "Women are all"
    // "... are stupid/dumb/annoying/evil etc." -> In what way? How so? What makes you say that?

    // If very strong language is used, such as "harm", "harmed", "abuse", "abused", "beat", etc.
    // insert a response such as "I'm sorry to hear that. How does speaking about this make you feel?"

    // If negative outcome, such as "she gets into trouble", then ask
    // What would it mean to you if "she gets into trouble?"

    // If you call the machine a: dumb/stupid machine/computer/clanker/bot/chatbot/AI then
    // Do computers frighten you?

    // If you start with "I am X" -> "How long have you been X"?
    // "You are _not listening_" -> "What makes you think I am _not listening_?"

    // Do you know what I mean? Do you get it? Do you understand?
    // I understand. Please, go on.

    // If love mentioned -> "Do you feel worthy of love?"
    // If "Yes/I do/Of course" -> "Go on."
    // If "No/Not" -> "Why not?"
    // If "Perhaps/Maybe/Aren't|Don't we all?" -> "What makes you uncertain?"

    // If a "Why" question is asked, and an empty reply comes back, like "Because it does/Simply because/because" -> "Don't other reasons come to mind? What other reasons might there be?"

    // People being referenced directly, such as mother, father, family, wife, husband, etc.
    // Tell me about your family.
    // Friends -> Tell me about your friends.

    // Please go on.
    // Can you think of a specific example?

    // X made me do something.
    // X made you do something?

    // printf("%s", response);

    // When the user types "bye" or "goodbye" the session is closed, and the conversation is
    // dumped into a .txt file in the current directory

    // Return "What makes you say that when no keyword is identified"
    // Use synonyms when appropriate to diversify the language

    return 0;
}
