import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Color;

/**
 * Show the interface that users could select which file he wants to display
 * and we can see that and save it
 * @author      YongFeng Ji
 * @version     2.0         
 * @since       12/08/2019
 */

public class Display extends JFrame {

	private JPanel contentPane;

	/**
	   * This is the main method which call the main frame(Interface)
	   * @param args Unused.
	   */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Display frame = new Display();
					frame.setVisible(true);
					frame.setTitle("Main Page");
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	   * This is the display interface function
	   */
	public Display() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBackground(Color.RED);
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JButton btnNewButton = new JButton("Result");
		btnNewButton.addActionListener(new ActionListener() {
			/**
			   * This is the open result function button
			   * @param none.
			   * @return Another interface.
			   */
			public void actionPerformed(ActionEvent e) {
				// open the result interface, close the old one
				Result re = new Result();
				dispose();
				re.setVisible(true);
			}
		});
		btnNewButton.setBounds(27, 77, 156, 84);
		contentPane.add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("Audit file");
		btnNewButton_1.addActionListener(new ActionListener() {
			/**
			   * This is the open audit file function button
			   * @param none.
			   * @return Another interface.
			   */
			public void actionPerformed(ActionEvent e) {
				// open the audit file interface, close the old one
				auditfile au = new auditfile();
				dispose();

				au.setVisible(true);
			}
		});
		btnNewButton_1.setBounds(254, 77, 156, 84);
		contentPane.add(btnNewButton_1);
	}

}
