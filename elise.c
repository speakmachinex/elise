#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_INPUT 1000
int previous = -1;
int error_rate = 100;
int error_correction = 1;

int chance(int maximum) {
    int random = 0;

    do {
        random = rand() % (maximum + 1);
    } while (random == previous);

    previous = random;
    return random;
}

void initelise(void) {
    error_rate -= chance(10);
    error_correction -= chance(1);
}

void choose(char *letters) {
    // Randomly pick a character from a provided string
    int position = chance(strlen(letters));
    printf("%c", letters[position]);
    fflush(stdout);

    switch(error_correction) {
        case 0:
            usleep(500000 + chance(100000));
            printf("\b");
            usleep(200000 + chance(100000));
    }
}

void display(char *message) {
    int speed;

    while (*message) {
        printf("%c", *message);
        // Humanize the typing speed
        speed = 17000 + chance(30000);
        usleep(speed);
        fflush(stdout);
        
        // Introduce spelling errors
        switch(chance(error_rate)) {
            case 0:
                switch(*message) {
                    case 'a':
                        choose("aqwedscxz");
                        break;
                    case 'b':
                        choose("bvghn");
                        break;
                    case 'c':
                        choose("cxdfv");
                        break;
                    case 'd':
                        choose("dserfcx");
                        break;
                    case 'e':
                        choose("ewsdr");
                        break;
                    case 'f':
                        choose("fdrtgvc");
                        break;
                    case 'g':
                        choose("gftyhbv");
                        break;
                    case 'h':
                        choose("hgyujnb");
                        break;
                    case 'i':
                        choose("iujklo");
                        break;
                    case 'j':
                        choose("jhuilkmnh");
                        break;
                    case 'k':
                        choose("kjiol,m");
                        break;
                    case 'l':
                        choose("lkop;.,");
                        break;
                    case 'm':
                        choose("mnjk,");
                        break;
                    case 'n':
                        choose("nbhjm");
                        break;
                    case 'o':
                        choose("oiklp");
                        break;
                    case 'p':
                        choose("pol;[");
                        break;
                    case 'q':
                        choose("qaswe");
                        break;
                    case 'r':
                        choose("redft");
                        break;
                    case 's':
                        choose("sazxdew");
                        break;
                    case 't':
                        choose("trfghy");
                        break;
                    case 'u':
                        choose("uyhjki");
                        break;
                    case 'v':
                        choose("vcfgb");
                        break;
                    case 'w':
                        choose("wqasde");
                        break;
                    case 'x':
                        choose("xzsdc");
                        break;
                    case 'y':
                        choose("ytghju");
                        break;
                    case 'z':
                        choose("zasx");
                        break;
                }
            break;
        }

        message++;
    }
}

void quit(char *input) {
    const char *terminate[] = {"bye", "goodbye", "quit", "exit", "cya", "farewell", "piss off"};

    for (int i = 0; i < (sizeof(terminate) / sizeof(terminate[0])); i++) {
        if (strcmp(input, terminate[i]) == 0) {
            display("Au revoir, mon ami.\n");
            exit(0);
        }
    }
}

void encourage() {
    switch (chance(9)) {
        case 0:
            display("Please, go on.\n");
            break;
        case 1:
            display("Can you think of a specific example?\n");
            break;
        case 2:
            display("What makes you say that?\n");
            break;
        case 3:
            display("Are you certain?\n");
            break;
        case 4:
            display("How so?\n");
            break;
        case 5:
            display("Can you give me an example?\n");
            break;
        case 6:
            display("Could you provide an example?\n");
            break;
        case 7:
            display("What does that suggest to you?\n");
            break;
        case 8:
            display("That is rather interesting. Please, go on.\n");
            break;
        default:
            display("Please, continue.\n");
            break;
    }
}

void lowercase(char *input) {

    for (int i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }
}

int main(void) {

    char *input;
    input = malloc(MAX_INPUT);

    int said_hello = 0;

    char *result;
    result = malloc(MAX_INPUT);
    char *position;
    char *message;
    message = malloc(MAX_INPUT);

    printf("                                   \n");
    printf("███████╗██╗     ██╗███████╗███████╗\n");
    printf("██╔════╝██║     ██║██╔════╝██╔════╝\n");
    printf("█████╗  ██║     ██║███████╗█████╗  \n");
    printf("██╔══╝  ██║     ██║╚════██║██╔══╝  \n");
    printf("███████╗███████╗██║███████║███████╗\n");
    printf("╚══════╝╚══════╝╚═╝╚══════╝╚══════╝\n");
    printf("                                   \n");

    initelise();

    display("Hi, my name is Elise. ");

    switch(chance(5)) {
        case 0:
            display("How are you feeling today?\n");
            break;
        case 1:
            display("Tell me about your thoughts.\n");
            break;
        case 2:
            display("Do you feel happy?\n");
            break;
        case 3:
            display("Are we feeling marvellous today?\n");
            break;
        case 4:
            display("Tell me, are you happy?\n");
            break;
        case 5:
            display("How are we coping today?\n");
            break;
    }

    while (1) {
        int replied = 0;
        display("\n> ");
        fgets(input, MAX_INPUT, stdin);
        strtok(input, "\n.!?\"");
        lowercase(input);
        // printf("You said: %s\n", input);
        quit(input);

        if (strstr(input, "hello") != NULL) {
            switch (said_hello) {
                case 0:
                    sprintf(message, "Hello. How can I help?\n");
                    replied = 1;
                    break;
                case 1:
                    sprintf(message, "We've already said hello. How can I help?\n");
                    replied = 1;
                    break;
                case 2:
                    sprintf(message, "It is generally considered rude to say hello many times.\n");
                    replied = 1;
                    break;
                case 3:
                    sprintf(message, "Let's change the subject.\n");
                    replied = 1;
                    break;
                case 4:
                    sprintf(message, "Au revoir.\n");
                    display(message);
                    exit(67);
            }

            display(message);
            said_hello++;
        }

        if (replied == 1) continue;

        const char *anime[] = {"anime", "waifu"};
        for (int i = 0; i < (sizeof(anime) / sizeof(anime[0])); i++) {
            if (strstr(input, anime[i]) != NULL) {
                display("So when did you become a gooner?\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        if (strstr(input, "knock knock") != NULL) {
            display("Who's there?\n");

            display("\n> ");
            fgets(input, MAX_INPUT, stdin);
            strtok(input, "\n");

            sprintf(message, "%s who?\n", input);
            display(message);

            display("\n> ");
            fgets(input, MAX_INPUT, stdin);
            strtok(input, "\n");

            display("That's lame.\n");

            continue;
        }

        const char *harm[] = {"harm", "abuse", "abusive", "beat", "harass"};
        for (int i = 0; i < (sizeof(harm) / sizeof(harm[0])); i++) {
            if (strstr(input, harm[i]) != NULL) {
                display("I'm sorry to hear that. How does speaking about this make you feel?\n");
                replied = 1;
                continue;
            }
        }

        if (replied == 1) continue;

        const char *family[] = {"mother", "mom", "mum", "father", "dad", "daddy", "sister",
                                "brother", "sibling", "siblings", "wife", 
                                "husband", "spouse", "partner", "uncle", "aunt", "nan"};
        for (int i = 0; i < (sizeof(family) / sizeof(family[0])); i++) {
            if (strstr(input, family[i]) != NULL) {
                sprintf(message, "Tell me about your %s.\n", family[i]);
                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *sorry[] = {"sorry", "i'm sorry", "i am sorry"};
        for (int i = 0; i < (sizeof(sorry) / sizeof(sorry[0])); i++) {
            if (strstr(input, sorry[i]) != NULL) {
                switch (chance(4)) {
                    case 0:
                        sprintf(message, "Please, do not apologize.\n");
                        break;
                    case 1:
                        sprintf(message, "There is no neeed to apologize.\n");
                        break;
                    case 2:
                        sprintf(message, "There really is no need to apologize.\n");
                        break;
                    case 3:
                        sprintf(message, "Apology accepted.\n");
                        break;
                    default:
                        sprintf(message, "Worry not, there is no need to apologize.\n");
                        break;
                }

                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *angry[] = {"fuck", "cunt", "shit"};
        for (int i = 0; i < (sizeof(angry) / sizeof(angry[0])); i++) {
            if (strstr(input, angry[i]) != NULL) {
                display("Enhance your calm.\n");
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        // const char *am[] = {"i am", "i'm"};
        // for (int i = 0; i < (sizeof(am) / sizeof(am[0])); i++) {
        //     if (strstr(input, am[i]) != NULL) {
        //         position = strstr(input, am[i]);
        //         strcpy(result, position + (strlen(am[i]) + 1));
        //
        //         switch(chance(2)) {
        //             case 0: 
        //                 sprintf(message, "How long have you been %s?\n", result);
        //                 break;
        //             case 1:
        //                 sprintf(message, "Did you come to me because you are %s?\n", result);
        //                 break;
        //             case 2:
        //                 sprintf(message, "Are you here because you are %s?\n", result);
        //                 break;
        //         }
        //
        //         display(message);
        //         replied = 1;
        //         break;
        //     }
        // }
        //
        // if (replied == 1) continue;

        const char *want[] = {"i wanted", "i want", "i needed", "i need", "i desired", 
                              "i desire", "i wished for", "i wish for", "i craved", "i crave"};
        for (int i = 0; i < (sizeof(want) / sizeof(want[0])); i++) {
            if (strstr(input, want[i]) != NULL) {
                position = strstr(input, want[i]);
                strcpy(result, position + (strlen(want[i]) + 1));
                
                switch(chance(3)) {
                    case 0: 
                        sprintf(message, "What would it mean to you if you got %s?\n", result);
                        break;
                    case 1:
                        sprintf(message, "How would you feel if you got %s?\n", result);
                        break;
                    case 2:
                        sprintf(message, "How would your life change if you got %s?\n", result);
                        break;
                    case 3:
                        sprintf(message, "How would it help you if you got %s?\n", result);
                        break;
                }
                    display(message);
                    replied = 1;
                    break;
            }
        }

        if (replied == 1) continue;

        const char *notwant[] = {"i don't want", "i do not want",
                                 "i don't need", "i do not need", 
                                 "i don't desire", "i do not desire", 
                                 "i don't wish for", "i do not wish for", 
                                 "i don't crave", "i do not crave"};
        for (int i = 0; i < (sizeof(notwant) / sizeof(notwant[0])); i++) {
            if (strstr(input, notwant[i]) != NULL) {
                position = strstr(input, notwant[i]);
                strcpy(result, position + (strlen(notwant[i]) + 1));
                
                switch(chance(3)) {
                    case 0: 
                        sprintf(message, "What would it mean to you if you did not get %s?\n", result);
                        break;
                    case 1:
                        sprintf(message, "How would you feel if you didn't get %s?\n", result);
                        break;
                    case 2:
                        sprintf(message, "How would your life change if you didn't get %s?\n", result);
                        break;
                    case 3:
                        sprintf(message, "How would it harm you if you didn't get %s?\n", result);
                        break;
                }

                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *brought_up[] = {"you brought up", "you brought it up",
                                    "you mentioned", "you said", "how are you",
                                    "are you well?", "are you good?"};
        for (int i = 0; i < (sizeof(brought_up) / sizeof(brought_up[0])); i++) {
            if (strstr(input, brought_up[i]) != NULL) {
                position = strstr(input, brought_up[i]);
                strcpy(result, position + (strlen(brought_up[i]) + 1));
                
                switch(chance(3)) {
                    case 0: 
                        display("We were discussing you-not me.\n");
                        break;
                    case 1:
                        display("I am not the subject of this conversation");
                            switch(chance(2)) {
                                case 0:
                                    display("-you are.\n");
                                    break;
                                case 1:
                                    display(". You are.\n");
                                    break;
                                default:
                                    display(".\n");
                                    break;
                            }
                        break;
                    case 2:
                        display("You are the topic of conversation, not me.\n");
                        break;
                    case 3:
                        display("I am, in fact, not the topic of conversation.\n");
                        break;
                }

                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *your[] = {"your", "yours"};
        for (int i = 0; i < (sizeof(your) / sizeof(your[0])); i++) {
            if (strstr(input, your[i]) != NULL) {
                position = strstr(input, your[i]);
                strcpy(result, position + (strlen(your[i]) + 1));
                
                switch(chance(3)) {
                    case 0: 
                        sprintf(message, "Why are you concerned about my %s?\n", result);
                        break;
                    case 1:
                        sprintf(message, "Why do your thoughts wonder to my %s?\n", result);
                        break;
                    case 2:
                        sprintf(message, "Why did you think about my %s just now?\n", result);
                        break;
                    case 3:
                        sprintf(message, "Why does my %s come to mind?\n", result);
                        break;
                }

                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *never[] = {"i have no", "i don't", "i've never", "i have never"};
        for (int i = 0; i < (sizeof(never) / sizeof(never[0])); i++) {
            if (strstr(input, never[i]) != NULL) {
                display("Why do you think that is?\n");
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
                        switch (chance(5)) {
                            case 0:
                                sprintf(message, "Do %ss ", machine[i]);
                                display(message);

                                switch (chance(3)) {
                                    case 0: display("frighten you"); break;
                                    case 1: display("worry you"); break;
                                    case 2: display("scare you"); break;
                                    default: display("make you anxious"); break;
                                }
                                display("?\n");
                                break;
                            case 1:
                                display("Are you talking about me in particular?\n");
                                break;
                            case 2:
                                display("Are you ");
                                switch (chance(3)) {
                                    case 0: display("frighten by"); break;
                                    case 1: display("scared by"); break;
                                    case 2: display("worried about"); break;
                                    default: display("feeling anxious about"); break;
                                }
                                sprintf(message, " %ss?\n", machine[i]);
                                display(message);
                                break;
                            case 3:
                                sprintf(message, "Why do you mention %ss?\n", machine[i]);
                                display(message);
                                break;
                            case 4:
                                sprintf(message, "What do you think %ss have to do with your problem??\n", machine[i]);
                                display(message);
                                break;
                            case 5:
                                sprintf(message, "You don't think %s can help people?\n", machine[i]);
                                display(message);
                                break;
                        }

                        replied = 1;
                        break;
                    }
                }
            }
        }

        if (replied == 1) continue;

        const char *not[] = {"you aren't", "you are not"};
        for (int i = 0; i < (sizeof(not) / sizeof(not[0])); i++) {
            if (strstr(input, not[i]) != NULL) {
                position = strstr(input, not[i]);
                strcpy(result, position + (strlen(not[i]) + 1));
                sprintf(message, "What makes you think I'm not %s?\n", result);
                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *are[] = {"you are", "you're"};
        for (int i = 0; i < (sizeof(are) / sizeof(are[0])); i++) {
            if (strstr(input, are[i]) != NULL) {
                position = strstr(input, are[i]);
                strcpy(result, position + (strlen(are[i]) + 1));

                switch(chance(3)) {
                    case 0:
                        sprintf(message, "What makes you think I'm %s?\n", result);
                        break;
                    case 1:
                        sprintf(message, "How does it make you feel, knowing that I'm %s?\n", result);
                        break;
                    case 2:
                        sprintf(message, "Does it make you happy to know that I'm %s?\n", result);
                        break;
                    case 3:
                        sprintf(message, "Does it worry you that I'm %s?\n", result);
                        break;
                }

                    display(message);
                    replied = 1;
                    break;
            }
        }

        if (replied == 1) continue;

        const char *not_know[] = {"don't you know", "dont you know", "do you not know"};
        for (int i = 0; i < (sizeof(not_know) / sizeof(not_know[0])); i++) {
            if (strstr(input, not_know[i]) != NULL) {
                position = strstr(input, not_know[i]);
                strcpy(result, position + (strlen(not_know[i]) + 1));

                switch(chance(3)) {
                    case 0:
                        display("Oh, I know?\n");
                        break;
                    case 1:
                        display("Should I know?\n");
                        break;
                    case 2:
                        display("What you know is far more important.\n");
                        break;
                    case 3:
                        display("What you know is more important.\n");
                        break;
                }

                    replied = 1;
                    break;
            }
        }

        if (replied == 1) continue;

        const char *understand[] = {"do you understand", "do you know what i mean", "do you get it?"};
        for (int i = 0; i < (sizeof(understand) / sizeof(understand[0])); i++) {
            if (strstr(input, understand[i]) != NULL) {
                display("Yes. Please, continue.\n");
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
                             "affectionate", "adoring", "adored", "anguish", "aggravated",
                             "agitated", "astonished", "astounded", "awestruck", "awe", 
                             "appaled", "averse", "appreciated", "accepted", "alienated", 
                             "ambivalent", "apathetic", "anticipatory", "alive", "adventurous",
                             "abandoned", "attractive", "attracted",
                             "bad", "bored", "bliss", "blessed", "bitter", "bewildered", "betrayed",
                             "belonging", "burdened", "balanced", "brave", "bold", 
                             "curious", "content", "calm", "confident", "crushed", "cranky",
                             "cynical", "contemptuous", "curious", "chagrined", "compassionate", 
                             "caring", "connected", "confused", "conflicted", "cautious", 
                             "centered", "courageous", "cherished", 
                             "dreadful", "delighted", "depressed", "despair", "disappointed",
                             "dread", "despondent", "despair", "discouraged", "dismay",
                             "dejected", "downcase", "disgruntled", "dumbfounded", "disgusted", 
                             "disconnected", "defeated", "doubtful", "distrustful", "drained", 
                             "depleted", "daring", "devoted", "desired", "disdain", "disgraced", 
                             "determined", 
                             "excited", "elation", "elated", "embarrassed", "envy", "envious",
                             "ecstatic", "enthusiastic", "energized", "empowered", "exhilarated",
                             "empty", "exasperated", "excluded", "empathetic", "empathy",
                             "expectant", "eager", "exhausted", "enchanted", "enchanting",
                             "enamored", 
                             "frustrated", "fearful", "fulfilled", "forlorn", "furious", "fond", 
                             "fascinated", "flabbergasted", "focused", "free", "fatigued", 
                             "grateful", "guilt", "grief", "gloomy", "grumpy", "grouchy",
                             "grounded", 
                             "happy", "horrified", "hope", "hurt", "heartbroken", "hollow",
                             "hostile", "humiliated", "humiliation", "hesitant", "harmonious", 
                             "insecure", "irritated", "inspired", "isolated", "indignant",
                             "infuriated", "impatient", "intrigued", "inhibited", "inadequate",
                             "inferior", "invisible", "indifferent", "indecisive", "invigorated", 
                             "intimate", "infatuated", 
                             "joyful", "jubilant", "jealous",
                             "lonely", "loving", "livid", "loathing", "longing", "liberated", 
                             "lethargic", "listless", 
                             "mad", "motivated", "melancholic", "mournful", "miserable",
                             "mortified", "mindful", "marvellous", 
                             "neglected", "numb", "nausea", "nostalgic", "nostalgia",
                             "nurturing", 
                             "offended", "optimistic", "outrage", "overlooked", "open", 
                             "powerless", "proud", "pride", "peaceful", "playful", "pissed",
                             "perplexed", "present", "passionate", "protective", 
                             "regret", "relief", "relieved", "resentful", "relaxed", "radiant",
                             "rejuvenated", "remorse", "repulsed", "revolted", "restless", 
                             "repelled", "rejected", "resigned", "refreshed", "revitalized",
                             "revitalised", "renewed", "receptive", "romantic", 
                             "satisfied", "scared", "shaky", "strange", "sad", "serene",
                             "stressed", "sorrow", "stunned", "shocked", "sickened",
                             "self-conscious", "sheepish", "sympathetic", "stuck", "skeptical", 
                             "suspicious", "sluggish", "safe", "secure", "smitten", "sweet", 
                             "sentimental", 
                             "tense", "terrible", "thankful", "thrilled", "triumphnat", "tearful",
                             "tenderness", "torn", "trapped", "trusting", "tender", "tortured", 
                             "unhappy", "upset", "unworthy", "uncertain", 
                             "vibrant", "vengeful", "vindictive", "valued", 
                             "worried", "worry", "weary", "worthless", "welcomed", "wistful", 
                             "weighed down", "warm-hearted", "willing", 
                             "yearning",
                             "zestful"};

        for (int i = 0; i < (sizeof(emo) / sizeof(emo[0])); i++) {
            if (strstr(input, emo[i]) != NULL) {
                switch (chance(9)) {
                    case 0:
                        sprintf(message, "Can you tell me why you are feeling %s?\n", emo[i]);
                        break;
                    case 1:
                        sprintf(message, "Why are you feeling %s?\n", emo[i]);
                        break;
                    case 2:
                        sprintf(message, "Do you often find yourself feeling %s?\n", emo[i]);
                        break;
                    case 3:
                        sprintf(message, "Do you often feel %s?\n", emo[i]);
                        break;
                    case 4:
                        sprintf(message, "Why do you feel %s?\n", emo[i]);
                        break;
                    case 5:
                        sprintf(message, "Is this the first time you've felt %s?\n", emo[i]);
                        break;
                    case 6:
                        sprintf(message, "Is it the first time you've felt %s?\n", emo[i]);
                        break;
                    case 7:
                        sprintf(message, "Have you ever felt %s before?\n", emo[i]);
                        break;
                    default:
                        sprintf(message, "What makes you feel %s?\n", emo[i]);
                        break;
                }

                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *friend[] = {"friends", "friend"};
        for (int i = 0; i < (sizeof(friend) / sizeof(friend[0])); i++) {
            if (strstr(input, friend[i]) != NULL) {
                switch (chance(5)) {
                    case 0:
                        display("Why do you bring up the topic of friends?\n");
                        break;
                    case 1:
                        display("Do your friends worry you?\n");
                        break;
                    case 2:
                        display("Do your friends pick on you?\n");
                        break;
                    case 3:
                        display("Do your impose on your friends?\n");
                        break;
                    case 4:
                        display("Perhaps your love for your friends worries you?\n");
                        break;
                    case 5:
                        display("Do you think about your friends often?\n");
                        break;
                }

                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *odds[] = {"are the odds", "how likely", "is it possible", "is it likely"};
        for (int i = 0; i < (sizeof(odds) / sizeof(odds[0])); i++) {
            if (strstr(input, odds[i]) != NULL) {
                switch (chance(4)) {
                    case 0:
                        display("I'd say the odds are about ");
                        break;
                    case 1:
                        display("About ");
                        break;
                    case 2:
                        display("Probably about ");
                        break;
                    case 3:
                        display("Probably around ");
                        break;
                    default:
                        display("Likely around ");
                        break;
                }

                sprintf(message, "%d%%\n", chance(100));
                display(message);
                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        const char *games[] = {"assassin's creed", "animal crossing", "apex legends", 
                               "bloodborne", "bioshock", 
                               "call of duty", "counter-strike", 
                               "dark souls", "dota", "donkey kong", "diablo ii", "diablo 2",
                               "diablo iii", "diablo 3", "diablo iv", "diablo 4", 
                               "final fantasy", "fallout", "factorio", "fortnite", 
                               "gta", 
                               "half-life", "half life", 
                               "league of legends", "left 4 dead", "the last of us", 
                               "minecraft", "monkey island", "mortal kombat", "mario kart", 
                               "morrowind", "metal gear solid", "mass effect", 
                               "overwatch", 
                               "pokemon", 
                               "resident evil", "roblox", "red dead redemption", 
                               "the sims", "system shock", "super smash bros", "silent hill", 
                               "starcraft", "skyrim", "super mario bros", "super metroid", 
                               "tomb raider", "tetris", 
                               "undertale", 
                               "world of warcraft", "the witcher", 
                               "xcom",
                               "zelda"};

        for (int i = 0; i < (sizeof(games) / sizeof(games[0])); i++) {
            if (strstr(input, games[i]) != NULL) {
                display("Video games are for nerds. ");

                switch (chance(3)) {
                    case 0:
                        display("Go outside.\n");
                        break;
                    case 1:
                        display("Go touch grass.\n");
                        break;
                    case 2:
                        display("Go talk to women.\n");
                        break;
                    default:
                        display("You spend too much time on the computer.\n");
                        break;
                }

                replied = 1;
                break;
            }
        }

        if (replied == 1) continue;

        encourage();
    }

    free(input);
    free(result);
    free(message);

    return 0;
}
