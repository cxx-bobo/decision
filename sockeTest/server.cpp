#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<iostream>

int main(){
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("192.168.1.110");  //具体的IP地址
    serv_addr.sin_port = htons(6666);  //端口
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);

    fd_set wr_fd;
    fd_set re_fd;
    struct timeval timeout{0, 30};
    char buff_re[256]{0};
    char buff_wr[256]{0};
    char str[] = "tars***";
    //sleep(5);
    printf("sleep done\n");
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    while(1){
        sleep(1);
        FD_ZERO(&wr_fd);
        FD_ZERO(&re_fd);
        FD_SET(clnt_sock, &re_fd);
        FD_SET(clnt_sock, &wr_fd);
        try{
            int r = select(clnt_sock+1, &re_fd, &wr_fd, NULL, &timeout);
            if(r >= 0){
                printf("%d\n", r);
                if(FD_ISSET(clnt_sock, &wr_fd)){
                    printf("write\n");
                    memcpy(buff_wr, str, sizeof(str));
                    write(clnt_sock, buff_wr, sizeof(buff_wr));
                }
                if(FD_ISSET(clnt_sock, &re_fd)){
                    printf("read\n");
                    read(clnt_sock, buff_re, sizeof(buff_re));
                    printf("%s\n", buff_re);
                }
            }
            //else break;
            else continue;
        }catch(std::exception& e){
            printf("error : %s\n", e.what());
        }
    }
    printf("exit.");
    //关闭套接字
    close(serv_sock);
    close(clnt_sock);
    return 0;
}
