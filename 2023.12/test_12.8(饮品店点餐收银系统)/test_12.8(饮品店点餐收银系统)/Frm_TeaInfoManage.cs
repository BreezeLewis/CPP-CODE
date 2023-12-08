using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Diagnostics.Eventing.Reader;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test_12._8_饮品店点餐收银系统_
{
    public partial class Frm_TeaInfoManage : Form
    {
        public Frm_TeaInfoManage()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string tea_name = txt_tea_name.Text.Trim();
            string price_min = txt_tea_price_min.Text.Trim();
            string price_mid = txt_tea_price_mid.Text.Trim();
            string price_max = txt_tea_price_max.Text.Trim();
            string status = cbx_status.Text.Trim();
            string picture_address = pictureBox1.ImageLocation;

            if(tea_name == "")
            {
                lbl_note.Text = "饮品名称不能为空";
                lbl_note.ForeColor = Color.Red;
                txt_tea_name.Focus();
            }
            else if(lbl_status.Text == "添加")
            {
                SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2; database=TeaShop_DB;Integrated Security=SSPI");
                conn.Open();
                string str = string.Format("insert into tea_info values('{0}', '{1}', '{2}', '{3}', '{4}', '{5}')", 
                    tea_name, price_min, price_mid, price_max, status, picture_address);

                SqlCommand cmd = new SqlCommand(str, conn);

                int i = cmd.ExecuteNonQuery();

                conn.Close();

                if(i > 0)
                {
                    lbl_note.Text = "饮品信息添加成功";
                    lbl_note.ForeColor = Color.Blue;
                    ClearTexBox();
                }
                else
                {
                    lbl_note.Text = "对不起，添加失败";
                    lbl_note.ForeColor = Color.Red;
                }    
            }
            else
            {
                SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2; database=TeaShop_DB;Integrated Security=SSPI");
                conn.Open();
                string str = string.Format("update tea_info set tea_name='{0}', min_price='{1}'," +
                    "mid_price= '{2}', max_price='{3}', tea_status='{4}', picture_address='{5}' where id='{6}'",
                    tea_name, price_min, price_mid, price_max, status, picture_address, teaid);

                SqlCommand cmd = new SqlCommand(str, conn);

                int i = cmd.ExecuteNonQuery();

                conn.Close();

                if (i > 0)
                {
                    lbl_note.Text = "饮品信息修改成功";
                    lbl_note.ForeColor = Color.Blue;
                    ClearTexBox();
                    DataBind_Tea();
                }
                else
                {
                    lbl_note.Text = "对不起，修改失败";
                    lbl_note.ForeColor = Color.Red;
                }
            }
        }

        protected void ClearTexBox()
        {
            txt_tea_name.Text = "";
            txt_tea_price_max.Text = "";
            txt_tea_price_mid.Text = "";
            txt_tea_price_min.Text = "";
            lbl_status.Text = "添加";

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void txt_tea_price_min_TextChanged(object sender, EventArgs e)
        {
            //txt_tea_price_min.Text = "";
        }

        private void txt_tea_price_min_MouseClick(object sender, MouseEventArgs e)
        {
            txt_tea_price_min.Text = "";
        }

        private void txt_tea_price_mid_MouseClick(object sender, MouseEventArgs e)
        {
            txt_tea_price_mid.Text = "";
        }

        private void txt_tea_price_max_MouseClick(object sender, MouseEventArgs e)
        {
            txt_tea_price_max.Text = "";
        }

        protected void DataBind_Tea()
        {
            SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2; database=TeaShop_DB;Integrated Security=SSPI");
            conn.Open();

            string str = "select * from tea_info";

            SqlDataAdapter da = new SqlDataAdapter(str, conn);

            DataTable dt = new DataTable();

            da.Fill(dt);

            conn.Close();

            lv_teainfo.Items.Clear();
            foreach(DataRow dr in dt.Rows)
            {
                ListViewItem myitem = new ListViewItem(dr["id"].ToString());
               
                myitem.SubItems.Add(dr["tea_name"].ToString());
                myitem.SubItems.Add(dr["min_price"].ToString());
                myitem.SubItems.Add(dr["mid_price"].ToString());
                myitem.SubItems.Add(dr["max_price"].ToString());
                myitem.SubItems.Add(dr["tea_status"].ToString());
                myitem.SubItems.Add(dr["picture_address"].ToString());


                lv_teainfo.Items.Add(myitem);
            }
        }

        private void Frm_TeaInfoManage_Load(object sender, EventArgs e)
        {
            DataBind_Tea();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataBind_Tea(btn_onsale.Text);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            DataBind_Tea(btn_saleout.Text);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            DataBind_Tea(btn_stopsale.Text);
        }

        protected void DataBind_Tea(string status)
        {
            SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2; database=TeaShop_DB;Integrated Security=SSPI");
            conn.Open();

            string str = string.Format("select * from tea_info where tea_status='{0}'", status);

            SqlDataAdapter da = new SqlDataAdapter(str, conn);

            DataTable dt = new DataTable();

            da.Fill(dt);

            conn.Close();

            lv_teainfo.Items.Clear();
            foreach (DataRow dr in dt.Rows)
            {
                ListViewItem myitem = new ListViewItem(dr["id"].ToString());

                myitem.SubItems.Add(dr["tea_name"].ToString());
                myitem.SubItems.Add(dr["min_price"].ToString());
                myitem.SubItems.Add(dr["mid_price"].ToString());
                myitem.SubItems.Add(dr["max_price"].ToString());
                myitem.SubItems.Add(dr["tea_status"].ToString());
                myitem.SubItems.Add(dr["picture_address"].ToString());


                lv_teainfo.Items.Add(myitem);
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if(teaid == "")
            {
                MessageBox.Show("请先选择要删除的饮品信息");
            }
            else
            {
                DialogResult result = MessageBox.Show("确定要删除选中的饮品信息？", "删除提示",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question);

                if(result == DialogResult.Yes)
                {
                    SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2; database=TeaShop_DB;Integrated Security=SSPI");
                    conn.Open();
                    string str = string.Format("delete from tea_info where id='{0}'", teaid);
                    SqlCommand cmd = new SqlCommand(str, conn);

                    int i = cmd.ExecuteNonQuery();

                    conn.Close();

                    if (i > 0)
                    {
                        lbl_note.Text = "饮品信息删除成功";
                        lbl_note.ForeColor = Color.Blue;
                        ClearTexBox();
                        DataBind_Tea();
                    }
                    else
                    {
                        lbl_note.Text = "对不起，删除失败";
                        lbl_note.ForeColor = Color.Red;
                    }
                }
            }
            


        }

        private void btn_select_image_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "图片|*.jpg;*.png";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                pictureBox1.ImageLocation = openFileDialog1.FileName;
                pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            }
        }

        string teaid = "";

        private void lv_teainfo_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(lv_teainfo.SelectedItems.Count > 0)
            {
                ListViewItem myitem = lv_teainfo.SelectedItems[0];

                teaid = myitem.SubItems[0].Text;
                txt_tea_name.Text = myitem.SubItems[1].Text;
                txt_tea_price_min.Text = myitem.SubItems[2].Text;
                txt_tea_price_mid.Text = myitem.SubItems[3].Text;
                txt_tea_price_max.Text = myitem.SubItems[4].Text;
                switch (myitem.SubItems[5].Text) //状态
                {
                    case "在售": cbx_status.SelectedIndex = 0; break;
                    case "售完": cbx_status.SelectedIndex = 1; break;
                    case "停售": cbx_status.SelectedIndex = 2; break;
                    default: cbx_status.SelectedIndex = 0; break;
                }
                pictureBox1.ImageLocation = myitem.SubItems[6].Text; //饮品图片
                pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
                lbl_status.Text = "修改"; //当前状态 
            }
        }

        private void txt_tea_price_min_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!char.IsDigit(e.KeyChar) && e.KeyChar != 8 && e.KeyChar != 13)
            { 
                e.Handled = true; return; 
            }
        }

        private void btn_reset_Click(object sender, EventArgs e)
        {
            ClearTexBox();
            lbl_status.Text = "添加";
            lbl_note.Text = "";
            teaid = "";
        }
    }
}
