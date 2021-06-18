/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package procesosapp;

import gnu.io.CommPortOwnershipListener;
import gnu.io.SerialPortEvent;
import gnu.io.SerialPortEventListener;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author Israel Cianca
 */
public class ProcesosGUI extends JFrame implements ActionListener,RecibeListener{
    JTextField Boleta;
    JLabel LED;
    JComboBox Puertos;
    JComboBox Paridad;
    JComboBox DataBit;
    JComboBox BaudeRate;
    JComboBox BitStop;
    JPanel Norte;
    JPanel Sur;
    JButton Establecer;
    JButton Encender;
    JButton Apagar;
    String PortNames[];
    int Paridades[]={0,1,2};
    int BaudeRates[]={9600,19200,38400,57600,115200};
    int BitStops[]={1,2,3};
    int DataBits[]={5,6,7,8};
    int BR,DB,P,BS,C,PR;
    int RanNum1;
    int RanNum2;
    RecibirThread Serial;
    public void Init()
    {
        int NumPuertos=0,i;
        Serial=new RecibirThread();
        NumPuertos=Serial.getNumPorts();
        PortNames=new String[NumPuertos];
        for(i=0;i<NumPuertos;i++)
            PortNames[i]=Serial.getNamePort(i);
        
        Puertos=new JComboBox(PortNames);
        PR=0;
        Puertos.addActionListener(this);
        
        String SParidades[]={"SIN PARIDAD","PARIDAD NON","PARIDAD PAR"};
        Paridad=new JComboBox(SParidades);
        P=Paridades[0];
        Paridad.addActionListener(this);
        
        String SBitStops[]={"1 BITSTOP","2 BIT STOP","1.5 BIT STOP"};
        BS=BitStops[0];
        BitStop=new JComboBox(SBitStops);
        BitStop.addActionListener(this);
        
        String SBaudeRates[]={"9600","19200","38400","57600","115200"};
        BaudeRate=new JComboBox(SBaudeRates);
        BaudeRate.addActionListener(this);
        BR=BaudeRates[0];
        
        String SDataBits[]={"5 BITS","6 BITS","7 BITS","8 BITS"};
        DataBit=new JComboBox(SDataBits);
        DB=DataBits[0];
        DataBit.addActionListener(this);
                
        Norte=new JPanel();
        Norte.setLayout(new FlowLayout());
        Norte.add(Puertos);
        Norte.add(BaudeRate);
        Norte.add(DataBit);
        Norte.add(BitStop);
        Norte.add(Paridad);
        Sur=new JPanel();
        Sur.setLayout(new FlowLayout());
        Establecer=new JButton("Establecer");
        Establecer.addActionListener(this);
        Encender=new JButton("Encender");
        Encender.addActionListener(this);
        Apagar=new JButton("Apagar");
        Apagar.addActionListener(this);
        LED=new JLabel("C�digo");
        LED.setBackground(Color.red);
        LED.setOpaque(true);
        Sur.add(Establecer);
        Sur.add(LED);
        Sur.add(Encender);
        Sur.add(Apagar);
        setLayout(new GridLayout(2,1));
        add(Norte);
        add(Sur);
        setSize(600,150);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
}

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource().equals((Paridad))){
            P=Paridades[Paridad.getSelectedIndex()];
        }
        else if (e.getSource().equals(BitStop)){
            BS=BitStops[BitStop.getSelectedIndex()];
        }
        else if (e.getSource().equals(BaudeRate)){
            BR=BaudeRates[BaudeRate.getSelectedIndex()];
        }
        else if (e.getSource().equals(DataBit)){
            DB=DataBits[DataBit.getSelectedIndex()];
        }
        else if (e.getSource().equals(Puertos)){
            PR=Puertos.getSelectedIndex();
        }
        else if (e.getSource().equals(Encender)){
            
            Serial.senData('E');
        }
        else if (e.getSource().equals(Apagar)){
            Serial.senData('B');
        }
        else if (e.getSource().equals(Establecer)){
            BaudeRate.setEnabled(false);
            DataBit.setEnabled(false);
            BitStop.setEnabled(false);
            Paridad.setEnabled(false);
            Puertos.setEnabled(false);
            Establecer.setEnabled(false);
            Serial.selectPort(PR);
            Serial.openPort(BR, DB, BS, P);
            Serial.setRecibeListener(this);
            Serial.Conect();
            
        }
    }

    @Override
    public void RecibirDato(int d) {
        if (d!=-1)
            LED.setText("Codigo:"+d);
    }

}
