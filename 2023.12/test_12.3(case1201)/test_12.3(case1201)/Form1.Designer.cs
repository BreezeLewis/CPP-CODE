namespace test_12._3_case1201_
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            TreeNode treeNode1 = new TreeNode("1.1");
            TreeNode treeNode2 = new TreeNode("1.2");
            TreeNode treeNode3 = new TreeNode("1.3");
            TreeNode treeNode4 = new TreeNode("第一章", new TreeNode[] { treeNode1, treeNode2, treeNode3 });
            TreeNode treeNode5 = new TreeNode("2.1");
            TreeNode treeNode6 = new TreeNode("2.2");
            TreeNode treeNode7 = new TreeNode("2.3");
            TreeNode treeNode8 = new TreeNode("第二章", new TreeNode[] { treeNode5, treeNode6, treeNode7 });
            treeView1 = new TreeView();
            btn_AddNode = new Button();
            btn_RemoveNode = new Button();
            label1 = new Label();
            textBox1 = new TextBox();
            SuspendLayout();
            // 
            // treeView1
            // 
            treeView1.Location = new Point(208, 50);
            treeView1.Name = "treeView1";
            treeNode1.Name = "节点1";
            treeNode1.Text = "1.1";
            treeNode2.Name = "节点2";
            treeNode2.Text = "1.2";
            treeNode3.Name = "节点3";
            treeNode3.Text = "1.3";
            treeNode4.Name = "节点0";
            treeNode4.Text = "第一章";
            treeNode5.Name = "节点5";
            treeNode5.Text = "2.1";
            treeNode6.Name = "节点6";
            treeNode6.Text = "2.2";
            treeNode7.Name = "节点7";
            treeNode7.Text = "2.3";
            treeNode8.Name = "节点4";
            treeNode8.Text = "第二章";
            treeView1.Nodes.AddRange(new TreeNode[] { treeNode4, treeNode8 });
            treeView1.Size = new Size(341, 203);
            treeView1.TabIndex = 0;
            treeView1.AfterSelect += treeView1_AfterSelect;
            // 
            // btn_AddNode
            // 
            btn_AddNode.Location = new Point(241, 294);
            btn_AddNode.Name = "btn_AddNode";
            btn_AddNode.Size = new Size(128, 60);
            btn_AddNode.TabIndex = 1;
            btn_AddNode.Text = "添加节点";
            btn_AddNode.UseVisualStyleBackColor = true;
            btn_AddNode.Click += btn_AddNode_Click;
            // 
            // btn_RemoveNode
            // 
            btn_RemoveNode.Location = new Point(415, 294);
            btn_RemoveNode.Name = "btn_RemoveNode";
            btn_RemoveNode.Size = new Size(121, 60);
            btn_RemoveNode.TabIndex = 2;
            btn_RemoveNode.Text = "删除节点";
            btn_RemoveNode.UseVisualStyleBackColor = true;
            btn_RemoveNode.Click += btn_RemoveNode_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(196, 394);
            label1.Name = "label1";
            label1.Size = new Size(99, 20);
            label1.TabIndex = 3;
            label1.Text = "当前选中节点";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(337, 391);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(199, 27);
            textBox1.TabIndex = 4;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(9F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Controls.Add(btn_RemoveNode);
            Controls.Add(btn_AddNode);
            Controls.Add(treeView1);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TreeView treeView1;
        private Button btn_AddNode;
        private Button btn_RemoveNode;
        private Label label1;
        private TextBox textBox1;
    }
}