#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT 100

void quit(char *response) {
    const char *terminate[] = {"bye", "goodbye", "quit", "exit", "cya", "farewell", "piss off"};

    for (int i = 0; i < (sizeof(terminate) / sizeof(terminate[0])); i++) {
        if (strcmp(response, terminate[i]) == 0) { exit(0); }
    }
}

void encourage() {
    int random = rand() % (10 + 1);
    switch (random) {
        case 0:
            printf("Please, go on.\n");
            break;
        case 1:
            printf("Can you think of a specific example?\n");
            break;
        case 2:
            printf("What makes you say that?\n");
            break;
        case 3:
            printf("Are you certain?\n");
            break;
        case 4:
            printf("How so?\n");
            break;
        case 5:
            printf("Can you give me an example?\n");
            break;
        case 6:
            printf("Could you provide an example?\n");
            break;
        case 7:
            printf("What does that suggest to you?\n");
            break;
        case 8:
            printf("That is quite interesting.\n");
            break;
        default:
            printf("Please, continue.\n");
            break;
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

        const char *am[] = {"i am", "i'm"};
        for (int i = 0; i < (sizeof(am) / sizeof(am[0])); i++) {
            if (strstr(input, am[i]) != NULL) {
                char *result;
                result = malloc(MAX_INPUT);
                char *position;
                position = strstr(input, am[i]);
                strcpy(result, position + (strlen(am[i]) + 1));
                printf("How long have you been %s?\n", result);
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
                        int random = rand() % (6 + 1);
                        switch (random) {
                            case 0:
                                printf("Do %ss ", machine[i]);
                                random = rand() % (4 + 1);
                                switch (random) {
                                    case 0: printf("frighten you"); break;
                                    case 1: printf("worry you"); break;
                                    case 2: printf("scare you"); break;
                                    default: printf("make you anxious"); break;
                                }
                                printf("?\n");
                                replied = 1;
                                break;
                            case 1:
                                printf("Are you talking about me in particular?\n");
                                replied = 1;
                                break;
                            case 2:
                                printf("Are you ");
                                random = rand() % (4 + 1);
                                switch (random) {
                                    case 0: printf("frighten by"); break;
                                    case 1: printf("scared by"); break;
                                    case 2: printf("worried about"); break;
                                    default: printf("feeling anxious about"); break;
                                }
                                printf(" %ss?\n", machine[i]);
                                replied = 1;
                                break;
                            case 3:
                                printf("Why do you mention %ss?\n", machine[i]);
                                replied = 1;
                                break;
                            case 4:
                                printf("What do you think %ss have to do with your problem??\n", machine[i]);
                                replied = 1;
                                break;
                            case 5:
                                printf("You don't think %s can help people?\n", machine[i]);
                                replied = 1;
                                break;
                        }
                    }
                }
            }
        }

        if (replied == 1) continue;

        const char *not[] = {"you aren't", "you are not"};
        for (int i = 0; i < (sizeof(not) / sizeof(not[0])); i++) {
            if (strstr(input, not[i]) != NULL) {
                char *result;
                result = malloc(MAX_INPUT);
                char *position;
                position = strstr(input, not[i]);
                strcpy(result, position + (strlen(not[i]) + 1));
                printf("What makes you think I'm not %s?\n", result);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *are[] = {"you are", "you're"};
        for (int i = 0; i < (sizeof(are) / sizeof(are[0])); i++) {
            if (strstr(input, are[i]) != NULL) {
                char *result;
                result = malloc(MAX_INPUT);
                char *position;
                position = strstr(input, are[i]);
                strcpy(result, position + (strlen(are[i]) + 1));
                printf("What makes you think I'm %s?\n", result);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *understand[] = {"do you understand", "do you know what i mean", "do you get it?"};
        for (int i = 0; i < (sizeof(understand) / sizeof(understand[0])); i++) {
            if (strstr(input, understand[i]) != NULL) {
                printf("Yes. Please, continue.\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;


        const char *anime[] = {"anime girl", "waifu"};
        for (int i = 0; i < (sizeof(anime) / sizeof(anime[0])); i++) {
            if (strstr(input, anime[i]) != NULL) {
                printf("So when did you become a gooner?\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *all[] = {"are all", "you all"};
        for (int i = 0; i < (sizeof(all) / sizeof(all[0])); i++) {
            if (strstr(input, all[i]) != NULL) {
                encourage();
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *emo[] = {"angry", "annoyed", "anxious", "apprehensive", "ashamed", "amused",
                             "affectionate", "adoring", "abandoned", "anguish", "aggravated",
                             "agitated", "astonished", "astounded", "awestruck", "awe", 
                             "appaled", "averse", "appreciated", "accepted", "alienated", 
                             "ambivalent", "apathetic", "anticipatory", "alive", "adventurous",
                             "bad", "bored", "bliss", "blessed", "bitter", "bewildered", "betrayed",
                             "belonging", "burdened", "balanced", "brave", "bold", 
                             "curious", "content", "calm", "confident", "crushed", "cranky",
                             "cynical", "contemptuous", "curious", "chagrined", "compassionate", 
                             "caring", "connected", "confused", "conflicted", "cautious", 
                             "centered", "courageous", 
                             "dreadful", "delighted", "depressed", "despair", "disappointed",
                             "dread", "despondent", "despair", "discouraged", "dismay",
                             "dejected", "downcase", "disgruntled", "dumbfounded", "disgusted", 
                             "disconnected", "defeated", "doubtful", "distrustful", "drained", 
                             "depleted", "daring", "devoted", 
                             "disdain", "disgraced", "determined", 
                             "excited", "elation", "elated", "embarrassed", "envy", "envious",
                             "ecstatic", "enthusiastic", "energized", "empowered", "exhilarated",
                             "empty", "exasperated", "excluded", "empathetic", "empathy",
                             "expectant", "eager", "exhausted", 
                             "frustrated", "fearful", "fulfilled", "forlorn", "furious",
                             "fascinated", "flabbergasted", "focused", "free", "fatigued", 
                             "grateful", "guilt", "grief", "gloomy", "grumpy", "grouchy",
                             "grounded", 
                             "happy", "horrified", "hope", "hurt", "heartbroken", "hollow",
                             "hostile", "humiliated", "humiliation", "hesitant", "harmonious", 
                             "insecure", "irritated", "inspired", "isolated", "indignant",
                             "infuriated", "impatient", "intrigued", "inhibited", "inadequate",
                             "inferior", "invisible", "indifferent", "indecisive", "invigorated", 
                             "intimate", 
                             "joyful", "jubilant", "jealous",
                             "lonely", "loving", "livid", "loathing", "longing", "liberated", 
                             "lethargic", "listless", 
                             "mad", "motivated", "melancholic", "mournful", "miserable",
                             "mortified", "mindful", 
                             "neglected", "numb", "nausea", "nostalgic", "nostalgia", 
                             "offended", "optimistic", "outrage", "overlooked", "open", 
                             "powerless", "proud", "pride", "peaceful", "playful", "pissed",
                             "perplexed", "present", "passionate", 
                             "regret", "relief", "relieved", "resentful", "relaxed", "radiant",
                             "rejuvenated", "remorse", "repulsed", "revolted", "restless", 
                             "repelled", "rejected", "resigned", "refreshed", "revitalized",
                             "revitalised", "renewed", "receptive", "romantic", 
                             "satisfied", "scared", "shaky", "strange", "sad", "serene",
                             "stressed", "sorrow", "stunned", "shocked", "sickened",
                             "self-conscious", "sheepish", "sympathetic", "stuck", "skeptical", 
                             "suspicious", "sluggish", "safe", "secure", 
                             "tense", "terrible", "thankful", "thrilled", "triumphnat", "tearful",
                             "tenderness", "torn", "trapped", "trusting", 
                             "unhappy", "upset", "unworthy", "uncertain", 
                             "vibrant", "vengeful", "vindictive", "valued", 
                             "worried", "weary", "worthless", "welcomed", "wistful", "willing", 
                             "weighed down", 
                             "yearning",
                             "zestful"};

        for (int i = 0; i < (sizeof(emo) / sizeof(emo[0])); i++) {
            if (strstr(input, emo[i]) != NULL) {
                int random = rand() % (9 + 1);
                switch (random) {
                    case 0:
                        printf("Can you tell me why you are feeling %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 1:
                        printf("Why are you feeling %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 2:
                        printf("Do you often find yourself feeling %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 3:
                        printf("Do you often feel %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 4:
                        printf("Why do you feel %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 5:
                        printf("Is this the first time you've felt %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 6:
                        printf("Is it the first time you've felt %s?\n", emo[i]);
                        replied = 1;
                        break;
                    case 7:
                        printf("Have you ever felt %s before?\n", emo[i]);
                        replied = 1;
                        break;
                    case 8:
                        printf("What makes you say that?\n");
                        replied = 1;
                        break;
                    default:
                        printf("What makes you feel %s?\n", emo[i]);
                        replied = 1;
                        break;
                }
            }
        }

        if (replied == 1) continue;

        const char *friend[] = {"friends", "friend"};
        for (int i = 0; i < (sizeof(friend) / sizeof(friend[0])); i++) {
            if (strstr(input, friend[i]) != NULL) {
                int random = rand() % (6 + 1);
                switch (random) {
                    case 0:
                        printf("Why do you bring up the topic of friends?\n");
                        replied = 1;
                        break;
                    case 1:
                        printf("Do your friends worry you?\n");
                        replied = 1;
                        break;
                    case 2:
                        printf("Do your friends pick on you?\n");
                        replied = 1;
                        break;
                    case 3:
                        printf("Do your impose on your friends?\n");
                        replied = 1;
                        break;
                    case 4:
                        printf("Perhaps your love for your friends worries you?\n");
                        replied = 1;
                        break;
                    case 5:
                        printf("Do you think about your friends often?\n");
                        replied = 1;
                        break;
                }
            }
        }

        if (replied == 1) continue;

        const char *odds[] = {"are the odds", "how likely", "is it possible", "is it likely"};
        for (int i = 0; i < (sizeof(odds) / sizeof(odds[0])); i++) {
            if (strstr(input, odds[i]) != NULL) {
                int random = rand() % (3 + 1);
                switch (random) {
                    case 0:
                        printf("I'd say the odds are about ");
                        replied = 1;
                        break;
                    case 1:
                        printf("About ");
                        replied = 1;
                        break;
                    case 2:
                        printf("Probably about ");
                        replied = 1;
                        break;
                    case 3:
                        printf("Probably around ");
                        replied = 1;
                        break;
                    default:
                        printf("Likely around ");
                        replied = 1;
                        break;
                }

                random = rand() % (100 + 1);
                printf("%d%%", random);
            }
        }

        if (replied == 1) continue;
        encourage();
    }

    // Strip punctuation: .,;!?()

    // When incorporating user input, translate terms such as "I" to "You"

    // If negative outcome, such as "she gets into trouble", then ask
    // What would it mean to you if "she gets into trouble?"

    // If love mentioned -> "Do you feel worthy of love?"
    // If "Yes/I do/Of course" -> "Go on."
    // If "No/Not" -> "Why not?"
    // If "Perhaps/Maybe/Aren't|Don't we all?" -> "What makes you uncertain?"

    // If a "Why" question is asked, and an empty reply comes back, like "Because it does/Simply|Just because/because" -> "Don't other reasons come to mind? What other reasons might there be?"

    // X made me do something.
    // X made you do something?

    // When the user types "bye" or "goodbye" the session is closed, and the conversation is
    // dumped into a .txt file in the current directory

    return 0;
}
