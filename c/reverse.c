// Reversing a string

void Reverse(char str[] )
{
  int front = 0;
  int back = strlen(str) ‐ 1;
  char t; /* A temporary place to put a character */
  while (front < back)
  {
    t = str[front];
    str[front] = str[back];
    str[back] = t;
    front++;
    back‐‐;
  }
}
