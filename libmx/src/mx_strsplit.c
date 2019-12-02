#include "libmx.h"

char **mx_strsplit(const char *s, char c){

	//считаем длинну для выдиления памяти под массив
	int counter1 = 0;
	int len = 0;
	while (s[counter1]){
		if (s[counter1] != c){
			len++;
		}
		counter1++;
	}

	//выделяем память под строку
	char **result = (char **)mx_strnew(len + 1);

	int i = 0;
	int tmp;
	int num_of_words = 0;
	while (s[i]){

		if(s[i] != c){
			tmp = i;

			while (s[i] != c && s[i]){
				i++;
			}

			int len_word = i - tmp;

			char *word = mx_strnew(len_word);

			for (int j = 0; tmp < i; tmp++, j++)
			{
				word[j] = s[tmp];
			}

			result[num_of_words] = word;
			num_of_words++;

		}
		else{
			i++;

		}

		
	}
	result[num_of_words] = NULL;
	
	return result;
}



