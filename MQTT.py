

#导入Pin模块
from machine import Pin
from machine import Timer
import time
import network
from simple import MQTTClient


#路由器WIFI账号和密码
ssid="ZB"
password="zb751216"
times=0
#WIFI连接
def wifi_connect():
    wlan=network.WLAN(network.STA_IF)  #STA模式
    wlan.active(True)  #激活
    wlan.disconnect()
    start_time=time.time()  #记录时间做超时判断
    
    if not wlan.isconnected():
        print("conneting to network...")
        wlan.connect(ssid,password)  #输入WIFI账号和密码
        
        while not wlan.isconnected():
            #超时判断,15 秒没连接成功判定为超时
            if time.time()-start_time>150:
                print("WIFI Connect Timeout!")
                return False
        print("network information:", wlan.ifconfig())
        return True
    
    else:
        print("network information:", wlan.ifconfig())
        return True

#设置 MQTT 回调函数,有信息时候执行
def mqtt_callback(topic,msg):
    print("topic: {}".format(topic))
    print("msg: {}".format(msg))
    
#接收数据任务
def mqtt_recv(tim):
    client.check_msg()

#发布数据任务
def mqtt_send(tim):
    global times
    times+=1
    client.publish("/public/pz_esp32/1", str(times))
    print(times)


#程序入口
if __name__=="__main__":
    
    if wifi_connect():
        SERVER="192.168.2.125"
        PORT=8883
        CLIENT_ID="PZ-ESP32"  #客户端ID
        TOPIC="/public/pz_esp32/1"  #TOPIC名称
        client = MQTTClient(CLIENT_ID, SERVER, PORT)  #建立客户端,ssl=True
        client.set_callback(mqtt_callback)  #配置回调函数
        client.connect()
        client.subscribe(TOPIC)  #订阅主题
        
        #开启RTOS定时器,周期 300ms，执行MQTT通信接收任务
        tim = Timer(0)
        tim.init(period=300, mode=Timer.PERIODIC,callback=mqtt_recv)
        
        tim1 = Timer(0)
        tim1.init(period=1000, mode=Timer.PERIODIC,callback=mqtt_send)
        


