#导入Pin模块
import time
import network


#路由器WIFI账号和密码
ssid="ZB"
password="zb751216"

#WIFI连接
def wifi_connect():
    wlan=network.WLAN(network.STA_IF)  #STA模式
    wlan.active(True)  #激活
    start_time=time.time()  #记录时间做超时判断
    
    if not wlan.isconnected():
        print("conneting to network...")
        wlan.connect(ssid,password)  #输入 WIFI 账号密码
        
        while not wlan.isconnected():
            #超时判断,15 秒没连接成功判定为超时
            if time.time()-start_time>15:
                print("WIFI Connect Timeout!")
                break
    
    else:
        print("network information:", wlan.ifconfig())
            

#程序入口
if __name__=="__main__":
    wifi_connect()
    #wlan = network.WLAN(network.STA_IF) # create station interface
    #wlan.active(True)       # activate the interface
    #wlan.scan()             # scan for access points