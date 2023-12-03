namespace test_12._3_case1201_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btn_AddNode_Click(object sender, EventArgs e)
        {
            TreeNode node1 = new TreeNode("第三章");

            TreeNode subnode1 = new TreeNode("3.1");
            TreeNode subnode2 = new TreeNode("3.2");

            node1.Nodes.Add(subnode1);
            node1.Nodes.Add(subnode2);

            treeView1.Nodes.Add(node1);
        }

        private void btn_RemoveNode_Click(object sender, EventArgs e)
        {
            if (treeView1 != null)
            {
                treeView1.SelectedNode.Remove();
            }
            else
            {
                MessageBox.Show("请先选择要删除的节点");
            }
        }

        private void treeView1_AfterSelect(object sender, TreeViewEventArgs e)
        {
            textBox1.Text = e.Node.Text;
        }
    }
}