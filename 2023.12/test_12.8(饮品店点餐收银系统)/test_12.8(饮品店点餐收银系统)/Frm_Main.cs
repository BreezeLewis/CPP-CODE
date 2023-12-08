using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;

namespace test_12._8_饮品店点餐收银系统_
{
    public partial class 饮品店点餐收银系统 : Form
    {
        public 饮品店点餐收银系统()
        {
            InitializeComponent();
        }

        private void Frm_Main_Load(object sender, EventArgs e)
        {
            //lbl_name.Text = ConfigurationManager.AppSettings["ReadName"];

        }

        

        
        private void Frm_Main_FormClosing_1(object sender, FormClosingEventArgs e)
        {
            DialogResult result = MessageBox.Show("确定关闭系统？", "关闭提示",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (result == DialogResult.Yes)
            {
                e.Cancel = false;
                this.Dispose();
                Application.Exit();
            }
            else
            {
                e.Cancel= true;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Frm_TeaInfoManage frm = new Frm_TeaInfoManage();
            frm.Show();
        }

        private void 系统管理ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 饮品信息管理ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 业绩统计分ToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void statusStrip1_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {

        }

        private void btn_TeaInfoManage_Click(object sender, EventArgs e)
        {
            Frm_TeaInfoManage frm = new Frm_TeaInfoManage();
            frm.Show();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            lbl_time.Text = DateTime.Now.ToString();
        }

        private void btn_MemberInfoManage_Click(object sender, EventArgs e)
        {
            Frm_MemberInfoManage frm = new Frm_MemberInfoManage();
            frm.Show();
        }
    }
}
