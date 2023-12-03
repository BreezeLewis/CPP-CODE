using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test_12._4_case1202_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GetRootDirectoryInfo();//加载根目录
        }

        protected void GetRootDirectoryInfo()
        {
            foreach (string dirname in Directory.GetLogicalDrives()) 
            { 
                DirectoryInfo dir = new DirectoryInfo(dirname);

                TreeNode node = new TreeNode(dirname);

                node.ToolTipText = dir.FullName;
                treeView1.Nodes.Add(node);
            }
        }

        private void treeView1_NodeMouseClick(object sender, TreeNodeMouseClickEventArgs e)
        {
            e.Node.Nodes.Clear();

            DirectoryInfo dir = new DirectoryInfo(e.Node.ToolTipText);
            GetSubDirectoryInfo(dir, e.Node);

            listView1.Items.Clear();

            foreach(FileInfo f in dir.GetFiles())
            {
                ListViewItem myitem = new ListViewItem(f.Name);
                myitem.SubItems.Add(f.Length.ToString());
                myitem.SubItems.Add(f.Length.ToString());

                listView1.Items.Add(myitem);
            }
        }

        protected void GetSubDirectoryInfo(DirectoryInfo dir, TreeNode node)
        {
            try
            {
                foreach (DirectoryInfo d in dir.GetDirectories())
                {
                    TreeNode tnode = new TreeNode(d.Name);
                    tnode.ToolTipText = d.FullName;
                    node.Nodes.Add(tnode);

                    GetSubDirectoryInfo(d, tnode);
                }
            }
            catch(Exception e)
            {
                MessageBox.Show(e.Message);
            }
        }
    }
}
