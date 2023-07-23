#include "main.h"
/************************* UNSIGNED NUMBER *************************/
/**
*print_unsigned - outputs unsigned number
*@types: arg ls
*@buffer: array to do print
*@flags:  calc flg
*@width: width
*@precision: precision
*@size: specifier
*Return: total char output
*/
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 10) + '0';
num /= 10;
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************* PRINT OCTAL  ****************/
/**
 * print_octal - prints octal
*@types: arg ls
*@buffer: array to print
*@flags:  calc flg
*@width: width
*@precision: precision
*@size: specifier
*Return: total chars output
*/
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = (num % 8) + '0';
num /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[i--] = '0';
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/************** PRINT HEX **************/
/**
*print_hexadecimal - print hex
*@types: arg ls
*@buffer: array to print
*@flags:  calc flg
*@width: width
*@precision: precision
*@size: specifier
*Return: total chars output
*/
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/************* PRINT HEX UPPER  **************/
/**
*print_hexa_upper - output hex upper
*@types: arg ls
*@buffer: array to print
*@flags:  calc flg
*@width: width
*@precision: precision
*@size: specifier
*Return: total chars output
*/
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}
/************** PRINT HEXX **************/
/**
*print_hexa - print hex
*@types: arg ls
*@map_to: value array
*@buffer: array to print
*@flags:  calc flg
*@flag_ch: calc flg
*@width: width
*@precision: precision
*@size: specifier
*@size: specifier
*Return: total char output
*/
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int i = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;
UNUSED(width);
num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[i--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (num > 0)
{
buffer[i--] = map_to[num % 16];
num /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[i--] = flag_ch;
buffer[i--] = '0';
}
i++;
return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
