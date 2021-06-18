/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package procesosapp;

/*
import gnu.io.CommPortIdentifier;
import gnu.io.CommPortOwnershipListener;
import gnu.io.PortInUseException;
import gnu.io.SerialPort;
import gnu.io.UnsupportedCommOperationException;
*/


import com.fazecast.jSerialComm.SerialPort;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Enumeration;




/**
 *
 * @author Israel
 */
public class RecibirThread extends Thread{
    private RecibeListener Listener;
    Enumeration puertos_libres;
    SerialPort[] Puertos;
    SerialPort Puerto;
    
    boolean FlagStop=true;
    
    public void setRecibeListener(RecibeListener L){
        Listener=L;
    }
    
   
    
    public RecibirThread(){
        Puertos=SerialPort.getCommPorts();    
    }
    
    public int getNumPorts(){
        return Puertos.length;
    }
    
    public String getNamePort(int index){
        return Puertos[index].getSystemPortName();
    }
    
    public void selectPort(int index){
        Puerto=Puertos[index];
    }
    
    public void openPort(int BaudeRate, int DataBits, int StopBits, int Parity){
       
            Puerto.openPort();
            Puerto.setBaudRate(BaudeRate);
            Puerto.setNumDataBits(DataBits);
            Puerto.setNumStopBits(StopBits);
            Puerto.setParity(Parity);
        
        
    }
    public void Conect(){
        FlagStop=false;
        start();
    }
    
    public void Disconnect(){
        FlagStop=true;
    }
    
    @Override
    public void run(){
        byte []buffer;
        buffer=new byte[1];
        while(FlagStop==false){
           if (Puerto.readBytes(buffer, 1)!=0)
                if (Listener!=null)
                    Listener.RecibirDato((int)buffer[0]);
                        
        }
        Puerto.closePort();
    }
    
    public void senData(int d){
        byte []buffer;
        buffer=new byte[1];
        buffer[0]=(byte)d;
        Puerto.writeBytes(buffer, 1);
    }
}
