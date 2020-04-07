import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class SimpleCalculator implements ActionListener
{
    JFrame fr;
    JPanel pa;
    JButton b1,b2,b3,b4,b5;
    JTextField t1,t2,t3;
    JLabel l1,l2,l3;
   SimpleCalculator()
    { 
        fr=new JFrame("Event");
        fr.setSize(600,400);
        pa=new JPanel();
        pa.setLayout(null);
        fr.add(pa);
        b1 =new JButton("Add");
        b2 =new JButton("Subtract");
        b3 =new JButton("Multiply");
        b4 =new JButton("Divide");
        b5 =new JButton("Reset");
        t1=new JTextField();
        t2=new JTextField();
        t3=new JTextField();
        l1=new JLabel("First Number");
        l2=new JLabel("Second Number");
        l3=new JLabel("Result");
        pa.add(b1);pa.add(b2);pa.add(b3);pa.add(b4);pa.add(b5);
        pa.add(t1);pa.add(t2);pa.add(t3);pa.add(l1);pa.add(l2);pa.add(l3);

        l1.setBounds(60,50,100,30);  t1.setBounds(180,50,150,30);
        l2.setBounds(60,100,100,30);  t2.setBounds(180,100,150,30);
        l3.setBounds(60,150,100,30);  t3.setBounds(180,150,150,30);

        b1.setBounds(60,200,80,30); 
        b2.setBounds(140,200,80,30);
        b3.setBounds(220,200,80,30);
        b4.setBounds(300,200,80,30);
        b5.setBounds(380,200,80,30);
        
        fr.setVisible(true);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);

    }
    public void actionPerformed(ActionEvent e) {
        int num1= Integer.parseInt(t1.getText());
        int num2= Integer.parseInt(t2.getText());
        if (e.getSource()==b1) {
            t3.setText(String.valueOf((num1+num2)));
        }
        if (e.getSource()==b2) {
 
      } t3.setText(String.valueOf((num1-num2)));
      if (e.getSource()==b3) {
        t3.setText(String.valueOf((num1*num2)));
      }
      if (e.getSource()==b4) {
        t3.setText(String.valueOf((num1/num2)));
      }
      if (e.getSource()==b5) {
          t1.setText(null);
          t2.setText(null);
          t3.setText(null);

      }
        
    }
    public static void main(String[] args) {
        new SimpleCalculator();
    }
}
