import javax.swing.*;
import java.awt.*;
import javax.swing.border.*;
import java.awt.event.*;
class ChuwaListener implements MouseListener
{
    JFrame fr;
    JPanel pa;
    JButton b1;
    Border bd1;
    JLabel l1;
    JPasswordField pf1;
    Icon hide,show;
    char ch;
    Font fo;
   ChuwaListener()
    { 
        fr=new JFrame("Event");
        fr.setSize(600,400);
        pa=new JPanel();
        pa.setLayout(null);
        fr.add(pa);
        fo=new Font("Eraser", Font.BOLD, 15);
        
        hide =new ImageIcon("hide.jpg");
        show =new ImageIcon("show.jpg");
     

        bd1=BorderFactory.createEmptyBorder();

        b1 =new JButton();
        l1=new JLabel("Enter Password");
        pf1 =new JPasswordField();
        
        l1.setFont(fo);
        b1.setIcon(show);
        
        ch=pf1.getEchoChar();
        b1.setBackground(Color.white);
        pf1.setBackground(Color.white);

        b1.setBorder(bd1);
        pf1.setBorder(bd1);

        pa.add(b1);pa.add(l1);pa.add(pf1);
        l1.setBounds(60,100,150,30);
        pf1.setBounds(220,100,150,30);
        b1.setBounds(370,100,30,30);
      
        fr.setVisible(true);
        b1.addMouseListener(this);
    }

    public void mouseClicked(MouseEvent e) {
        
    }

    public void mouseEntered(MouseEvent e) {
        
    }

    public void mouseExited(MouseEvent e) {
        
    }

    public void mousePressed(MouseEvent e) {
        b1.setIcon(hide);
        pf1.setEchoChar((char)0);
        
    }

    public void mouseReleased(MouseEvent e) {
        b1.setIcon(show);
        pf1.setEchoChar(ch);
    }
    public static void main(String[] args) {
        new ChuwaListener();
    }
}
