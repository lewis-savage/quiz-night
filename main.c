#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

typedef struct{
    char *question;
    char *answer;
} question;


void swap(int *a, int *b);

int load_questions(question ***questions, char *path);

int do_quiz(question **questions, int difficulty, int num_questions);

void populate_count_array(int *array, int n);

void shuffle(int array[], int size);

int read_word(char* word, size_t word_size);

void write_results(char* file_name, int correct_answers, int number_questions, int difficulty);

void strip_ext(char *fname);
char separator();
int main(int argc, char *argv[]) {
    if(argc>3){
        printf("Too many arguments");
        return 0;
    }
    setbuf(stdout,0);
    question** questions;
    int num_questions = load_questions(&questions,argv[1]);
    //SECTION: Reading difficulty level
    int difficulty = atoi(argv[2]);

    printf("Number of questions in this quiz: %d\n",num_questions);
    printf("Difficulty level chosen: %d\n\n",difficulty);


    int correct_answers = do_quiz(questions,difficulty,num_questions);

    //Extract the file name from the full path
    char* path = malloc(sizeof(char)*strlen(argv[1]));
    strcpy(path,argv[1]);

    char* file_name;
    file_name = strrchr(path,separator())+1;

    strip_ext(file_name);
    write_results(file_name,correct_answers,num_questions,difficulty);
    return 0;
}

char separator()
{
#if defined _WIN32 || defined __CYGWIN__
    return '\\';
#else
    return '/';
#endif
}
int do_quiz(question **questions, int difficulty, int num_questions) {
    //Seed the random questions
    time_t t;
    srand((unsigned) time(&t));
    int asked = 0;
    int correct = 0;
    int question_indexes[num_questions];
    populate_count_array(question_indexes,num_questions);
    shuffle(question_indexes,num_questions);
    int *resultsarray = calloc(num_questions,sizeof(int));
    for (int question_index = 0; question_index < num_questions; ++question_index) {

        int random_question = question_indexes[question_index];
        question* current_question = questions[random_question];
        printf("%s\n",current_question->question);
        int answer_length = strlen(current_question->answer);
        int real_difficulty = difficulty;
        if(difficulty==6){
            real_difficulty = (rand()%5)+1;
        }
        if(real_difficulty==1){
            printf("?");
        } else if (real_difficulty == 2) {
            for (int i = 0; i < answer_length; ++i) {
                printf("- ");
            }
        } else if(real_difficulty == 3){
            for (int i = 0; i < answer_length; ++i) {
                if(i==0 || i == answer_length-1){
                    printf("%c ",current_question->answer[i]);
                }else {
                    printf("- ");
                }
            }
        } else if(real_difficulty == 4){
            int index_a = rand()%answer_length;
            int index_b;
            while(1){
                index_b = rand()%answer_length;
                if(index_a!=index_b){
                    break;
                }
            }
            for (int i = 0; i < answer_length; ++i) {
                if(i==index_a || i == index_b){
                    printf("%c ",current_question->answer[i]);
                }else {
                    printf("- ");
                }
            }
        } else if(real_difficulty==5){
            int word_indexes[answer_length];
            populate_count_array(word_indexes,answer_length);
            shuffle(word_indexes,answer_length);
            for (int i = 0; i < answer_length; ++i) {
                printf("%c ",toupper(current_question->answer[word_indexes[i]]));
            }
        }
        //+1 because of the null terminator;
        char* word = malloc(answer_length+1);
        read_word(word,answer_length+1);
        int guessCorrect = 1;
        for (int j = 0; j < answer_length; ++j) {
            if(tolower(word[j])!=tolower(current_question->answer[j])){
                guessCorrect = 0;
            }
        }
        if(guessCorrect == 1){
            printf("Correct!\n");
            resultsarray[question_index]=1;
            ++correct;
        }else{
            printf("Incorrect!\n");
        }
        asked++;
        printf("Score: %d/%d\n",correct,asked);
    }
    printf("All questions answered!\n");
    printf("Your score is: %d/%d\n",correct,asked);
    if(correct!=asked){
        printf("Do you want to view the answers to the questions you got wrong? (Y/N)\n");
        int c;
        char confirm;
        scanf(" %c",&confirm);
        if(tolower(confirm) != 'n'){
            for (int i = 0; i < num_questions; ++i) {
                if(resultsarray[i]==0) {
                    question *current_question = questions[question_indexes[i]];
                    printf("Question: %s Answer: %s \n", current_question->question, current_question->answer);
                }
            }
        }
        while ((c = getchar()) != '\n' && c != EOF);
    }
    free(resultsarray);
    free(questions);

    return correct;

}



int read_word(char *word, size_t word_size){
    printf("\nGuess: ");
    assert(word_size > 0 && word_size <= INT_MAX);
    size_t i = 0;
    int ch;
    while ((ch = fgetc(stdin)) != EOF) {  // Read until EOF ...
        if (i + 1 < word_size) {
            word[i++] = ch;
        }
        if (ch == '\n') {  // ... or end of line
            break;
        }
    }
    word[i] = '\0';
    if (i == 0) {
        return EOF;
    }
    return i;
}
void shuffle(int array[], int size){
    srand(time(NULL));
    for (int i = size-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);

        // Swap arr[i] with the element at random index
        swap(&array[i], &array[j]);
    }
}

void populate_count_array(int *array, int n){
    for (int i = 0; i < n; ++i) {
        array[i]=i;
    }
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int load_questions(question*** questions, char* path){
    //SECTION: Reading file contents
    FILE *file = fopen(path,"r");
    //buffer for reading lines
    char currentline[100];
    assert(file != NULL);
    int lines = 0;
    question** local_questions = malloc(sizeof(question*));
    while(fgets(currentline, sizeof(currentline),file)!=NULL){
        char *q_pointer;
        //Remove trailing new line
        strtok(currentline,"\n");
        //Get index of the question mark
        q_pointer = strchr(currentline,'?');
        int index = (int)(q_pointer-currentline)+2;
        int lineLength = strlen(currentline);
        int answerLength = lineLength-index;

        question* current_question = malloc(sizeof(question*));
        current_question->question = malloc(sizeof(char*)*index-1);
        current_question->answer = malloc(sizeof(char*)*answerLength);

        strncpy(current_question->question,currentline,index-1);
        strncpy(current_question->answer,currentline+index,answerLength);

        current_question->answer[answerLength]='\0';
        current_question->question[index-1]='\0';
        local_questions[lines] = current_question;
        lines++;
        local_questions=realloc(local_questions,(lines+1)*sizeof(char*));
    }
    fclose(file);
    *questions = local_questions;
    return lines;
}

void strip_ext(char *fname)
{
    char *end = fname + strlen(fname);

    while (end > fname && *end != '.' && *end != '\\' && *end != '/') {
        --end;
    }
    if ((end > fname && *end == '.') &&
        (*(end - 1) != '\\' && *(end - 1) != '/')) {
        *end = '\0';
    }
}

void write_results(char *file_name, int correct_answers, int number_questions, int difficulty) {
    FILE *fp = fopen("quiz_history.txt","a+");
    fprintf(fp,"Quiz Name: %s, Questions answered correctly: %d, Total questions: %d, Difficulty: %d\n" ,file_name,correct_answers,number_questions,difficulty);
    fclose(fp);
}

