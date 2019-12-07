package voting;

import java.awt.BorderLayout;
import java.awt.Desktop;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.awt.event.ActionEvent;

public class display extends JFrame {

	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		String s = null;
		try {
			// Process provides control of native processes started by ProcessBuilder.start and Runtime.exec.
			// getRuntime() returns the runtime object associated with the current Java application.
      //Process p = Runtime.getRuntime().exec("");
			BufferedReader stdInput = new BufferedReader(new InputStreamReader(System.in));
 
			// read the output from the command
			System.out.println("Enter a command and press CTRL + D to stop\nActually... type \"Display\" without quotes:");
			while ((s = stdInput.readLine()) != null) {
        if (s.compareTo("Display") == 0) {
      		EventQueue.invokeLater(new Runnable() {
            public void run() {
	            try {
		            display frame = new display();
		            frame.setVisible(true);
	            } catch (Exception e) {
		            e.printStackTrace();
	            }
            }
          });
        }
				System.out.println(s);
			}
			System.exit(0);
		} catch (IOException e) {
			System.out.println("exception happened - here's what I know: ");
			e.printStackTrace();
			System.exit(-1);
		}	
	}

	/**
	 * Create the frame.
	 */
	

	
	public display() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JButton btnDisplay = new JButton("display");
		btnDisplay.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

			     
//						try {
//						     Desktop.getDesktop().open(new java.io.File("../1.txt"));
//						     
//						    } catch(Exception e1) {
//						     e1.printStackTrace();
//						    }
//				
				
				
				
			}
		});
		contentPane.add(btnDisplay, BorderLayout.CENTER);
	}

}
