#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 100

void quit(char *response) {
    const char *terminate[] = {"bye", "goodbye", "quit", "exit", "cya", "farewell"};

    for (int i = 0; i < (sizeof(terminate) / sizeof(terminate[0])); i++) {
        if (strcmp(response, terminate[i]) == 0) { exit(0); }
    }
}

// void lowercase(char *response, char *input) {
//
//     for (int i = 0; i < strlen(response); i++) {
//         response[i] = tolower(response[i]);
//     }
//     strncpy(input, response, 50);
//     printf("We got here.\n");
// }

int main(void) {

    char *response;
    char *input;
    input = malloc(MAX_INPUT);

    int said_hello = 0;

    printf("                                   \n");
    printf("███████╗██╗     ██╗███████╗███████╗\n");
    printf("██╔════╝██║     ██║██╔════╝██╔════╝\n");
    printf("█████╗  ██║     ██║███████╗█████╗  \n");
    printf("██╔══╝  ██║     ██║╚════██║██╔══╝  \n");
    printf("███████╗███████╗██║███████║███████╗\n");
    printf("╚══════╝╚══════╝╚═╝╚══════╝╚══════╝\n");
    printf("                                   \n");

    printf("Hi! My name is Elise. What seems to be your boggle?\n");

    while (1) {
        int replied = 0;
        printf("\n> ");
        fgets(input, MAX_INPUT, stdin);
        strtok(input, "\n");
        // lowercase(response, input);
        // printf("You said: %s\n", input);
        quit(input);

        if (strstr(input, "hello") != NULL) {
            switch (said_hello) {
                case 0:
                    printf("Hello. How can I help?\n");
                    replied = 1;
                    break;
                case 1:
                    printf("We've already said hello. How can I help?\n");
                    replied = 1;
                    break;
                case 2:
                    printf("It is generally considered rude to say hello many times.\n");
                    replied = 1;
                    break;
                default:
                    printf("Let's change the subject.\n");
                    replied = 1;
                    break;
            }

            said_hello++;
        }

        if (replied == 1) continue;

        const char *harm[] = {"harm", "abuse", "abusive", "beat", "harass"};
        for (int i = 0; i < (sizeof(harm) / sizeof(harm[0])); i++) {
            if (strstr(input, harm[i]) != NULL) {
                printf("I'm sorry to hear that. How does speaking about this make you feel?\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *family[] = {"mother", "mom", "mum", "father", "dad", "daddy", "sister",
                                "sis", "bro", "brother", "sibling", "siblings", "wife", 
                                "husband", "spouse", "partner", "uncle", "aunt", "nan"};
        for (int i = 0; i < (sizeof(family) / sizeof(family[0])); i++) {
            if (strstr(input, family[i]) != NULL) {
                printf("Tell me about your %s.\n", family[i]);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *never[] = {"i have no", "i don't", "i've never", "i have never"};
        for (int i = 0; i < (sizeof(never) / sizeof(never[0])); i++) {
            if (strstr(input, never[i]) != NULL) {
                printf("Why do you think that is?\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *angry[] = {"fuck", "cunt", "shit"};
        for (int i = 0; i < (sizeof(angry) / sizeof(angry[0])); i++) {
            if (strstr(input, angry[i]) != NULL) {
                printf("Enhance your calm.\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *emotion[] = {"sad", "depressed", "angry", "frustrated", "annoyed"};
        for (int i = 0; i < (sizeof(emotion) / sizeof(emotion[0])); i++) {
            if (strstr(input, emotion[i]) != NULL) {
                printf("Why are you %s?\n", emotion[i]);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *dumb[] = {"dumb", "stupid", "silly", "idiotic", "useless"};
        const char *machine[] = {"machine", "computer", "clanker", "bot", "ai"};
        for (int i = 0; i < (sizeof(dumb) / sizeof(dumb[0])); i++) {
            if (strstr(input, dumb[i]) != NULL) {
                for (int i = 0; i < (sizeof(machine) / sizeof(machine[0])); i++) {
                    if (strstr(input, machine[i]) != NULL) {
                        printf("Do computers frighten you?\n");
                        replied = 1;
                        break;
                    }
                }
            }
        }

        if (replied == 1) continue;

        const char *are[] = {"you are", "you're"};
        for (int i = 0; i < (sizeof(are) / sizeof(are[0])); i++) {
            if (strstr(input, are[i]) != NULL) {
                char *result;
                result = malloc(MAX_INPUT);
                char *you_are;
                you_are = strstr(input, are[i]);
                strcpy(result, you_are + (strlen(are[i]) + 1));
                printf("What makes you think I'm %s?\n", result);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        printf("Please, go on.\n");

    }



    // Strip punctuation: .,;!?()

    // Use pre-defined responses, sometimes incorporating the user input
    // When incorporating user input, translate terms such as "I" to "You"
    // Eg. If a user says "I'm feeling depressed" -> "Why do you believe/feel/think you are depressed?
    // If emotional term is used in combination with I, ask why "emotional term".
    // How long have you been feeling "emotional term"

    // Emotional language that describes a person or a group
    // "Men are all" alike/the same
    // "Women are all"
    // "... are stupid/dumb/annoying/evil etc." -> In what way? How so? What makes you say that?

    // If negative outcome, such as "she gets into trouble", then ask
    // What would it mean to you if "she gets into trouble?"

    // If you start with "I am X" -> "How long have you been X"?
    // "You are _not listening_" -> "What makes you think I am _not listening_?"

    // Do you know what I mean? Do you get it? Do you understand?
    // I understand. Please, go on.

    // If love mentioned -> "Do you feel worthy of love?"
    // If "Yes/I do/Of course" -> "Go on."
    // If "No/Not" -> "Why not?"
    // If "Perhaps/Maybe/Aren't|Don't we all?" -> "What makes you uncertain?"

    // If a "Why" question is asked, and an empty reply comes back, like "Because it does/Simply because/because" -> "Don't other reasons come to mind? What other reasons might there be?"


    // Please go on.
    // Can you think of a specific example?

    // X made me do something.
    // X made you do something?

    // When the user types "bye" or "goodbye" the session is closed, and the conversation is
    // dumped into a .txt file in the current directory

    // Return "What makes you say that when no keyword is identified"
    // Use synonyms when appropriate to diversify the language

    return 0;
}
