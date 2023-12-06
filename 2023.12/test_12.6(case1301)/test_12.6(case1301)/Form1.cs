using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace test_12._6_case1301_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        SqlDataAdapter da = null;
        DataTable dt = null;
        private void Form1_Load(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection("Data Source=LAPTOP-QO7UP5K2;" +
                "database=DB_CASE1301; Integrated Security=SSPI");

            conn.Open();

            string str = string.Format("select * from Book_Info");

            da = new SqlDataAdapter(str, conn);

            dt = new DataTable();

            da.Fill(dt);

            conn.Close();

            dataGridView1.DataSource = dt;

            SqlCommandBuilder sqlCmdBuilder = new SqlCommandBuilder(da);
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.RowIndex >= 0 && e.RowIndex < dataGridView1.Rows.Count && e.ColumnIndex >= 0 && e.ColumnIndex < dataGridView1.ColumnCount)
            {
                textBox1.Text = dataGridView1.Rows[e.RowIndex].Cells[e.ColumnIndex].Value.ToString(); 
            }
            else
            { textBox1.Text = ""; }
        }

        private void btn_Save_Click(object sender, EventArgs e)
        {
            try
            {
                da.Update(dt);
                dt.AcceptChanges();
                MessageBox.Show("图书信息更新成功！");
            }
            catch(Exception er)
            {
                MessageBox.Show("图书信息更新失败，原因为：" + er.Message);
            }
        }

        private void btn_Delete_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确认删除选中的图书信息？", "删除提示", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                int i = dataGridView1.CurrentRow.Index;
                dataGridView1.Rows.RemoveAt(i);
                btn_Save.PerformClick();
            }
        }
    }
}
