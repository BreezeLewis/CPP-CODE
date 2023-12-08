using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test_12._8_饮品店点餐收银系统_
{
    public partial class Frm_Login : Form
    {
        public Frm_Login()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void btn_login_Click(object sender, EventArgs e)
        {
            if(txt_username.Text.Trim() == "")
            {
                MessageBox.Show("请输入用户名！");
                txt_username.Focus();
            }
            else if(txt_password.Text.Trim() == "")
            {
                MessageBox.Show("请输入密码！");
                txt_password.Focus();
            }
            else
            {
                SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2; database=TeaShop_DB;Integrated Security=SSPI");
                conn.Open();

                string str = string.Format("select * from user_info where account='{0}' and" +
                    " passwd='{1}'", txt_username.Text, txt_password.Text);

                SqlDataAdapter da = new SqlDataAdapter(str, conn);

                DataTable dt = new DataTable();

                da.Fill(dt);

                conn.Close();

                if(dt.Rows.Count > 0 )
                {
                    饮品店点餐收银系统 frm = new 饮品店点餐收银系统();
                    frm.Show();
                    this.Hide();
                    //this.Show();
                }
                else
                {
                    MessageBox.Show("对不起，用户名或密码不正确！");
                }
            }
        }
    }
}
