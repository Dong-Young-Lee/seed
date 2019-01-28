#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>


int stack[100001];
int size_of_stack = 0;

void push(int value) {
	stack[size_of_stack] = value;
	size_of_stack += 1;
}

int pop() {
	if (size_of_stack == 0) {
		return -1;
	}
	else {
		size_of_stack -= 1;
		return stack[size_of_stack];
	}
}

int size() {
	return size_of_stack;
}

int empty() {
	if (size_of_stack == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int top() {
	if (size_of_stack == 0) {
		return -1;
	}
	else {
		return stack[size_of_stack - 1];
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	while (n--) {
		char str[10];
		scanf("%s", str);

		if (!strcmp(str, "push")) {
			int input_number;
			scanf("%d", &input_number);
			push(input_number);
		}
		else if (!strcmp(str, "pop")) {
			printf("%d\n", pop());
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", empty());
		}
		else if (!strcmp(str, "top")) {
			printf("%d\n", top());
		}
	}

	return 0;

}