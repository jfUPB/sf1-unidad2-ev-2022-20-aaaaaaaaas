using UnityEngine;
using System.IO.Ports;
using TMPro;

enum TaskState
{
    INIT,
    WAIT_COMMANDS
}

public class Serial : MonoBehaviour
{
    private static TaskState taskState = TaskState.INIT;
    private SerialPort _serialPort;
    private byte[] buffer;
    public TextMeshProUGUI btn1State;
    public TextMeshProUGUI btn2State;
    public TextMeshProUGUI btn3State;
    public TMP_Dropdown ledSelector;
    public TMP_Dropdown ledState;
    


    private int counter = 0;

    void Start()
    {
        _serialPort = new SerialPort();
        _serialPort.PortName = "/dev/ttyUSB0";
        _serialPort.BaudRate = 115200;
        _serialPort.DtrEnable = true;
        _serialPort.NewLine = "\n";
        _serialPort.Open();
        Debug.Log("Open Serial Port");
        buffer = new byte[128];
    }

    void Update()
    {
        counter++;

        switch (taskState)
        {
            case TaskState.INIT:
                taskState = TaskState.WAIT_COMMANDS;
                Debug.Log("WAIT COMMANDS");
                break;
            case TaskState.WAIT_COMMANDS:

                if (_serialPort.BytesToRead > 0)
                {
                    for(int i = 1; i < 4; i++)
                    {
                        if (i == 1)
                        {
                            string response = _serialPort.ReadLine();
                            Debug.Log(response);
                            btn1State.text = response;
                        } else if (i == 2)
                        {
                            string response = _serialPort.ReadLine();
                            Debug.Log(response);
                            btn2State.text = response;
                        }else if (i == 3)
                        {
                            string response = _serialPort.ReadLine();
                            Debug.Log(response);
                            btn3State.text = response;
                        }
                    }
                    
                }

                break;
            default:
                Debug.Log("State Error");
                break;
        }
    }

    public void BTNREAD()
    {
        _serialPort.Write("readBUTTONS\n");
        Debug.Log("Send readBUTTONS");

        
    }
    public void BTREADLED()
    
    {
        if (ledSelector.options[ledSelector.value].text == "1")
        {
            if (ledState.options[ledState.value].text == "ON")
            {
                _serialPort.Write("led1ON\n");
                Debug.Log("Send led1ON");
            } else {
                _serialPort.Write("led1OFF\n");
                Debug.Log("Send led1OFF");
            }

        }
          if (ledSelector.options[ledSelector.value].text == "2")
        {
            if (ledState.options[ledState.value].text == "ON")
            {
                _serialPort.Write("led2ON\n");
                Debug.Log("Send led2ON");
            } else {
                _serialPort.Write("led2OFF\n");
                Debug.Log("Send led2OFF");
            }

        }
          if (ledSelector.options[ledSelector.value].text == "3")
        {
            if (ledState.options[ledState.value].text == "ON")
            {
                _serialPort.Write("led3ON\n");
                Debug.Log("Send led3ON");
            } else {
                _serialPort.Write("led3OFF\n");
                Debug.Log("Send led3OFF");
            }

        }

    }

    
    
}