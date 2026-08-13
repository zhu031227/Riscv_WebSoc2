/*
 * http.c — RISC-V WebSoC 控制面板 (稳定版)
 */
#include "inc/http.h"

const char *main_page =
    "HTTP/1.1 200 OK\r\n"
    "Connection: close\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html><meta charset='UTF-8'><title>RISC-V WebSoC</title>"
    "<style>"
    "body{font-family:Arial;background:#1a1a2e;color:#eee;text-align:center;padding:20px}"
    "h2{color:#e94560}"
    "a{display:inline-block;padding:8px 16px;margin:4px;border-radius:4px;font-size:13px;text-decoration:none;font-weight:bold}"
    ".on{background:#00c853;color:#fff}.off{background:#e94560;color:#fff}"
    "input{padding:5px;margin:3px;border:1px solid #444;border-radius:3px;background:#1a1a2e;color:#eee;font-family:monospace;width:130px}"
    "button{padding:6px 16px;margin:4px;border:none;border-radius:4px;cursor:pointer;font-weight:bold}"
    ".rd{background:#0f3460;color:#00c853}.wr{background:#e94560;color:#fff}"
    "</style>"
    "<h2>RISC-V WebSoC</h2>"

    "<p>LED:</p>"
    "<a class=on href='/set?addr=0010&data=0000000F&mode=write'>ALL ON</a>"
    "<a class=off href='/set?addr=0010&data=00000000&mode=write'>ALL OFF</a>"
    "<br>"
    "<a class=on href='/set?addr=0010&data=00000001&mode=write'>LED0</a>"
    "<a class=on href='/set?addr=0010&data=00000002&mode=write'>LED1</a>"
    "<a class=on href='/set?addr=0010&data=00000004&mode=write'>LED2</a>"
    "<a class=on href='/set?addr=0010&data=00000008&mode=write'>LED3</a>"

    "<br><br>"
    "<form action=/set method=GET>"
    "Addr:<input name=addr value=0010> Data:<input name=data value=0000000F>"
    "<br>"
    "<button class=rd name=mode value=read>Read</button>"
    "<button class=wr name=mode value=write>Write</button>"
    "</form>";

const char *post_response =
    "HTTP/1.1 200 OK\r\n"
    "Connection: close\r\n"
    "Content-Type: text/html\r\n\r\n"
    "<!DOCTYPE html><meta charset='UTF-8'><title>RISC-V WebSoC</title>"
    "<style>"
    "body{font-family:Arial;background:#1a1a2e;color:#eee;text-align:center;padding:40px}"
    "h2{color:#00c853}.info{color:#aaa;line-height:2.2}"
    ".a{color:#e94560;font-family:monospace}.d{color:#00c853;font-family:monospace}"
    "a{display:inline-block;padding:8px 24px;background:#e94560;color:#fff;border-radius:4px;text-decoration:none;margin-top:12px}"
    "</style>"
    "<h2>XXX操作成功</h2>"
    "<div class=info>Register: <span class=a>0x00000000</span><br>Data: <span class=d>0x88888888</span></div>"
    "<a href='/'>返回</a>";
