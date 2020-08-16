#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
int main(){
    //创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("192.168.1.110");  //具体的IP地址
    serv_addr.sin_port = htons(6666);  //端口
    if(!connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))){
        printf("connect error.");
    };
   
    //读取服务器传回的数据
    fd_set wr_fd;
    fd_set re_fd;
    struct timeval timeout{0, 30};
    char buff_re[256]{0};
    char buff_wr[256]{0};
    char str[] = "gogo2019***";
    while(1){
        sleep(1);
        //printf("sleep done\n");
    FD_ZERO(&wr_fd);
    FD_ZERO(&re_fd);
    FD_SET(sock, &re_fd);
    FD_SET(sock, &wr_fd);
    int r = select(sock+1, &re_fd, &wr_fd, NULL, &timeout);
    if(r >= 0){
        printf("%d\n", r);
        if(FD_ISSET(sock, &wr_fd)){
            printf("write\n");
            memcpy(buff_wr, str, sizeof(str));
            printf("write: %s\n", buff_wr);
            write(sock, buff_wr, sizeof(buff_wr));
        }
        if(FD_ISSET(sock, &re_fd)){
            printf("read\n");
            read(sock, buff_re, sizeof(buff_re));
            printf("read: %s\n", buff_re);
        }
    }
    else break;
    }
    
    //printf("Message form server: %s\n", buffer);
   
    //关闭套接字
    printf("exit.");
    close(sock);
    return 0;
}