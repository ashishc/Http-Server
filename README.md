Http-Server
===========
C implementation of http Server that can host any http websites.

##Running
Compile using MakeFile and run with the options available.

```
make
http_server -d sample_site
```
##Options

###-d : 
Set directory location of website to be hosted.

```
http_serve -d sample_site
```

###-p : 
Set port number of server.

```
http_serve -d sample_site -p 9000
```

###-f : 
Run server using multiple processes.
For every new request process will get created.

```
http_serve -f -d sample_site -p 9000
```

###-t : 
Run server using threads.
For every new request thread will get created.

```
http_serve -t -d sample_site -p 9000
```

###-w :
Run server with limited numbers of worked threads.
```
http_serve -w 10 -d sample_site -p 9000
```

###-q :
Limit the queue size for thread pool strategy.
Only use this option with -w.
```
http_serve -w 10 -q 10 -d sample_site -p 9000
```

###Serial Operation :
If no f,t,w options are provided, server will run in serial mode.
```
http_serve -w 10 -d sample_site -p 9000
```

###-v:
Set log level to ERROR,WARNING,INFO or DEBUG.
```
http_serve -w 10 -d sample_site -p 9000 -v ERROR
http_serve -w 10 -d sample_site -p 9000 -v WARNING
http_serve -w 10 -d sample_site -p 9000 -v INFO
http_serve -w 10 -d sample_site -p 9000 -v DEBUG
```

##Signals Handled:

### SIGINT|SIGTERM : 
    Use ctrl + c to shutdown server or use kill.
    
### SIGUSR2:
    Change the current log level.
```
    If process id for my server is 34567
    kill -SIGUSR2 34567
```
```
    Current log level INFO
```

### SIGUSR1:
    Display server statistics.
```
    If process id for my server is 34567
    kill -SIGUSR1 34567
```
```
-----------------------------SERVER iNFO-----------------------------
CURRENT LOG LEVELS               : ERROR,WARNING,INFO
Document Root                    : sample_site
Port No                          : 9000
Response Strategy                : Serial Operation
Total Requests handled           : 32
Total amount of data transferred : 415922 bytes
Total uptime                     : 0 hr,0 min, 15.325913309 seconds
Total time spent serving requets : 0 hr,0 min, 2.7236844123925454905 seconds
Avg time spent serving requests  : 0.08511513788 seconds
---------------------------------------------------------------------
```



    
