#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct
{
	int front, rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

//오류 함수
void error(const char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화 함수
void init_queue(DequeType* q)
{
	q->front = q->rear = 0;
}
//포화상태 검사
int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
//공백상태 검사
int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}
//원형큐 출력 함수
void deque_print(DequeType* q)
{
	printf("Deque(front = %d, rear = %d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}
//rear 함수
void add_rear(DequeType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[(q->rear)] = item;
}
element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

//front 함수
void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("큐가 포화상태");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
int delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void eliminate_space(char* str, char* str_copy);
int IsPalindrome(char* str_copy);

int main()
{
	char str[50], str_copy[50], x;

	printf("Enter a string( or input 'exit'):");
	gets(str);
	eliminate_space(str, str_copy);

	for (int i = 0; i < strlen(str_copy); i++)
	{
		if (isupper(str_copy[i]))
			str_copy[i] = tolower(str_copy[i]);
	}

	if (IsPalindrome(str_copy))
		printf("%s is a palindrome.\n", str);
	else
		printf("%s is not a palindrome.\n", str);
	printf("Try Again? Y/y continues, other quits.");

	scanf_s("%c", &x);
	if (x == 'y' || x == 'Y')
	{
		str[0] = '\0';
		str_copy[0] = '\0';
		main();
	}
	return 0;
}

void eliminate_space(char* str, char* str_copy)
{
	int i = 0, j = 0;
	for (; i < strlen(str); i++)
	{
		if (str[i] != ' ')
			str_copy[j++] = str[i];
	}
	str_copy[j] = '\0';
}

int IsPalindrome(char* str_copy)
{
	int length = strlen(str_copy),
		i = 0;

	for (i = 0; i < (length / 2); i++)
	{
		if (str_copy[i] != str_copy[length - i - 1])
		{
			return 0;
		}
	}
	return 1;

}