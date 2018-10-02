// 解析命令行参数 -> 读取trace -> 初始化cache -> 逐行运行operation -> 输出结果。
#include "cachelab.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#define max 1000;
struct cache_line //行
{
    int valid_bit;  //有效位
    int tag;        //标记位
    int LRUcounter; //LRU需要位数
} cache_lines;
struct operation
{
    char op;     //操作指令
    int address; //地址
    int size;    //字节大小
} operations;

int S, E; //组数和行数
cache_lines[S][E];      //cache的数据结构

void read_trace(FILE *fp,operations operation [],int visable)      //需要用到fscanf函数，来解析各个字段
{
    char op;
    int address;
    int size;
    int i=0,num=0;
    while(fscanf(fp,"%c %x,%d",&op,&address,&size)==-1)//文件结尾返回EOF
    {
        if(visable==1)      //-v选项，显示每条信息
        {
            printf("%c %x,%d",op,address,size);
        }
        operation[i].op = op;
        operation[i].address = address;
        operation[i].size = size;
        i++;
    }
    num = i;
    for(i=0;i<num;i++)
    {
        switch(opteration[i].op)
        {
            case 'I ':
            {

            }
            case 'M' :
            {
                 
            }
            case 'L' :
            {
                 
            }
            case 'S' :
            {
                 
            }
        }
    }
}


int main(int arg, char *argv[])
{
    opertations  opteration[max];
    char opt;
    int visable = 0;
    int set_number, line_number, byte_number;
    FILE *fp;
    const char *help_message = "Usage: \"Your complied program\" [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n";


    while (opt == getopt(argc, *argv[], "hvs:E:b:t:") != -1) //解析参数,因为输入字符串是Usage: ./csim-ref [-hv] -s <s> -E <E> -b <b> -t <tracefile>等价于
    // hv 没有参数，s有参数，E参数，b有参数，t有参数  冒号表示参数，一个冒号就表示这个选项后面必须带有参数
    // 此函数会返回在argv 中下一个的选项字母，此字母会对应参数optstring 中的字母。
    // 如果选项字符串里的字母后接着冒号“:”，则表示还有相关的参数，全域变量optarg 即会指向此额外参数。
    {

        switch (opt)
        {
            case 'h': //显示选项的用法信息
            {
                printf("%s", help_message);
                exit(0);
            }
            case 'v': //显示每条指令的情况是否显示
            {
                visable = 1;
                break;
            }

            case 's':
            {
                set_number = 1 << atoi(optarg); //2^s组atoi能够将字符串转换成int类型的
            }

            case 'E':
            {
                line_number = atoi(optarg); //每组E行
            }
            case 'b':
            {
                byte_number = 1 << atoi(optarg); //每个块2^b字节
            }

            case 't':           //文件路径
            {
                fp = fopen(optarg, "r");
                break;
            }
            default:        
            {
                printf("%s", help_message);
                exit(0);
                break;
            }
        }
    }
    read_trace(fp,operation,visable);       //读取trace的操作    
  //  find_set(int s, int b);
   // find_line(int s, int b);

    printSummary(0, 0, 0);
    return 0;
}
