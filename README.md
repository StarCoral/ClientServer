# ClientServer
網路連線容器 ★ try to test mixed os by StarCoral

### DockerFile建立

1.&nbsp;&nbsp;建立一個新的資料夾：

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`mkdir ClientServer`

2.&nbsp;&nbsp;準備需使用的檔案：

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`vim client.c`

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`vim server.c`

3.&nbsp;&nbsp;建立image：

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`docker build -t riyazhu/unp:ClientServer . --no-cache`

### 使用docker run運行(不同節點)：
+ server：
   + 執行container：
   
     `docker run -it -p 51717:51717 -h server --name server  riyazhu/unp:ClientServer`

   + 運行server：
   
     `./server 51717`

+ client：
   + 執行container：
    
     `docker run -it -p 51717:51717 -h client --name client  riyazhu/unp:ClientServer`

   + 運行client：
    
     `./client $serverIP 51717`

