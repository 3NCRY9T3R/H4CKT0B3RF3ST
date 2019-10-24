import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class EventHandling implements ActionListener
{
    JFrame fr;
    JPanel pa;
    JButton b1,b2,b3,b4,b5;
    EventHandling()
    { 
        fr=new JFrame("Event");
        fr.setSize(600,400);
        pa=new JPanel();
        fr.add(pa);
        b1 =new JButton("Red");
        b2 =new JButton("Green");
        b3 =new JButton("Blue");
        b4 =new JButton("Black");
        b5 =new JButton("Orange");
        pa.add(b1);pa.add(b2);pa.add(b3);pa.add(b4);pa.add(b5);
        fr.setVisible(true);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);

    }
    
    public void actionPerformed(ActionEvent e) {
        //  System.out.println(e.getActionCommand()+" Button Clicked"); //one liner for all button clicked with their label

          if (e.getSource()==b1) {
              pa.setBackground(Color.red);
          }
          if (e.getSource()==b2) {
            //System.out.println("Green Button is clicked");
            pa.setBackground(Color.green);
        }
        if (e.getSource()==b3) {
            // System.out.println("Blue Button is clicked");
            pa.setBackground(Color.BLUE);
        }
        if (e.getSource()==b4) {
            // System.out.println("Black Button is clicked");
            pa.setBackground(Color.black);
        }
        if (e.getSource()==b5) {
            // System.out.println("Orange Button is clicked");
            pa.setBackground(Color.orange);
        }
       
    }

    public static void main(String[] args) {
        EventHandling e=new EventHandling();
    }
}
