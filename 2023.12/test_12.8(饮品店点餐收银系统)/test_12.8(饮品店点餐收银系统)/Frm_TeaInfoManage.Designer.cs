namespace test_12._8_饮品店点餐收银系统_
{
    partial class Frm_TeaInfoManage
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.lbl_status = new System.Windows.Forms.Label();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.btn_select_image = new System.Windows.Forms.Button();
            this.btn_reset = new System.Windows.Forms.Button();
            this.btn_save = new System.Windows.Forms.Button();
            this.cbx_status = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.txt_tea_price_max = new System.Windows.Forms.TextBox();
            this.txt_tea_price_mid = new System.Windows.Forms.TextBox();
            this.txt_tea_price_min = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txt_tea_name = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.lv_teainfo = new System.Windows.Forms.ListView();
            this.columnHeader1 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader2 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader3 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader4 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader5 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader6 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeader7 = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.btn_delete = new System.Windows.Forms.Button();
            this.btn_stopsale = new System.Windows.Forms.Button();
            this.btn_saleout = new System.Windows.Forms.Button();
            this.btn_onsale = new System.Windows.Forms.Button();
            this.lbl_note = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.lbl_status);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Controls.Add(this.btn_reset);
            this.groupBox1.Controls.Add(this.btn_save);
            this.groupBox1.Controls.Add(this.cbx_status);
            this.groupBox1.Controls.Add(this.label6);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.txt_tea_price_max);
            this.groupBox1.Controls.Add(this.txt_tea_price_mid);
            this.groupBox1.Controls.Add(this.txt_tea_price_min);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.txt_tea_name);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Location = new System.Drawing.Point(56, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(656, 268);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "编辑饮品信息   当前操作：";
            // 
            // lbl_status
            // 
            this.lbl_status.AutoSize = true;
            this.lbl_status.Location = new System.Drawing.Point(198, 0);
            this.lbl_status.Name = "lbl_status";
            this.lbl_status.Size = new System.Drawing.Size(37, 15);
            this.lbl_status.TabIndex = 14;
            this.lbl_status.Text = "添加";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.pictureBox1);
            this.groupBox3.Controls.Add(this.btn_select_image);
            this.groupBox3.Location = new System.Drawing.Point(387, 34);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(230, 221);
            this.groupBox3.TabIndex = 13;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "饮品图片";
            // 
            // btn_select_image
            // 
            this.btn_select_image.Location = new System.Drawing.Point(6, 24);
            this.btn_select_image.Name = "btn_select_image";
            this.btn_select_image.Size = new System.Drawing.Size(88, 31);
            this.btn_select_image.TabIndex = 0;
            this.btn_select_image.Text = "选择图片";
            this.btn_select_image.UseVisualStyleBackColor = true;
            this.btn_select_image.Click += new System.EventHandler(this.btn_select_image_Click);
            // 
            // btn_reset
            // 
            this.btn_reset.Location = new System.Drawing.Point(218, 221);
            this.btn_reset.Name = "btn_reset";
            this.btn_reset.Size = new System.Drawing.Size(80, 34);
            this.btn_reset.TabIndex = 12;
            this.btn_reset.Text = "重置";
            this.btn_reset.UseVisualStyleBackColor = true;
            this.btn_reset.Click += new System.EventHandler(this.btn_reset_Click);
            // 
            // btn_save
            // 
            this.btn_save.Location = new System.Drawing.Point(111, 221);
            this.btn_save.Name = "btn_save";
            this.btn_save.Size = new System.Drawing.Size(80, 34);
            this.btn_save.TabIndex = 11;
            this.btn_save.Text = "保存";
            this.btn_save.UseVisualStyleBackColor = true;
            this.btn_save.Click += new System.EventHandler(this.button2_Click);
            // 
            // cbx_status
            // 
            this.cbx_status.FormattingEnabled = true;
            this.cbx_status.Items.AddRange(new object[] {
            "在售",
            "售完",
            "停售"});
            this.cbx_status.Location = new System.Drawing.Point(140, 178);
            this.cbx_status.Name = "cbx_status";
            this.cbx_status.Size = new System.Drawing.Size(158, 23);
            this.cbx_status.TabIndex = 10;
            this.cbx_status.Text = "在售";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(53, 181);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(52, 15);
            this.label6.TabIndex = 9;
            this.label6.Text = "状态：";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(243, 140);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(37, 15);
            this.label5.TabIndex = 8;
            this.label5.Text = "大份";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(243, 109);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(37, 15);
            this.label4.TabIndex = 7;
            this.label4.Text = "中份";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(243, 78);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 15);
            this.label3.TabIndex = 6;
            this.label3.Text = "小份";
            // 
            // txt_tea_price_max
            // 
            this.txt_tea_price_max.Location = new System.Drawing.Point(140, 137);
            this.txt_tea_price_max.Name = "txt_tea_price_max";
            this.txt_tea_price_max.Size = new System.Drawing.Size(88, 25);
            this.txt_tea_price_max.TabIndex = 5;
            this.txt_tea_price_max.Text = "0";
            this.txt_tea_price_max.MouseClick += new System.Windows.Forms.MouseEventHandler(this.txt_tea_price_max_MouseClick);
            // 
            // txt_tea_price_mid
            // 
            this.txt_tea_price_mid.Location = new System.Drawing.Point(140, 106);
            this.txt_tea_price_mid.Name = "txt_tea_price_mid";
            this.txt_tea_price_mid.Size = new System.Drawing.Size(88, 25);
            this.txt_tea_price_mid.TabIndex = 4;
            this.txt_tea_price_mid.Text = "0";
            this.txt_tea_price_mid.MouseClick += new System.Windows.Forms.MouseEventHandler(this.txt_tea_price_mid_MouseClick);
            // 
            // txt_tea_price_min
            // 
            this.txt_tea_price_min.Location = new System.Drawing.Point(140, 75);
            this.txt_tea_price_min.Name = "txt_tea_price_min";
            this.txt_tea_price_min.Size = new System.Drawing.Size(88, 25);
            this.txt_tea_price_min.TabIndex = 3;
            this.txt_tea_price_min.Text = "0";
            this.txt_tea_price_min.MouseClick += new System.Windows.Forms.MouseEventHandler(this.txt_tea_price_min_MouseClick);
            this.txt_tea_price_min.TextChanged += new System.EventHandler(this.txt_tea_price_min_TextChanged);
            this.txt_tea_price_min.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_tea_price_min_KeyPress);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(53, 78);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "饮品价格：";
            // 
            // txt_tea_name
            // 
            this.txt_tea_name.Location = new System.Drawing.Point(141, 31);
            this.txt_tea_name.Name = "txt_tea_name";
            this.txt_tea_name.Size = new System.Drawing.Size(157, 25);
            this.txt_tea_name.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label1.Location = new System.Drawing.Point(53, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(82, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "饮品名称：";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.lv_teainfo);
            this.groupBox2.Controls.Add(this.btn_delete);
            this.groupBox2.Controls.Add(this.btn_stopsale);
            this.groupBox2.Controls.Add(this.btn_saleout);
            this.groupBox2.Controls.Add(this.btn_onsale);
            this.groupBox2.Location = new System.Drawing.Point(56, 332);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(656, 289);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "饮品信息列表";
            // 
            // lv_teainfo
            // 
            this.lv_teainfo.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeader1,
            this.columnHeader2,
            this.columnHeader3,
            this.columnHeader4,
            this.columnHeader5,
            this.columnHeader6,
            this.columnHeader7});
            this.lv_teainfo.FullRowSelect = true;
            this.lv_teainfo.GridLines = true;
            this.lv_teainfo.HideSelection = false;
            this.lv_teainfo.Location = new System.Drawing.Point(9, 45);
            this.lv_teainfo.MultiSelect = false;
            this.lv_teainfo.Name = "lv_teainfo";
            this.lv_teainfo.Size = new System.Drawing.Size(635, 228);
            this.lv_teainfo.TabIndex = 4;
            this.lv_teainfo.UseCompatibleStateImageBehavior = false;
            this.lv_teainfo.View = System.Windows.Forms.View.Details;
            this.lv_teainfo.SelectedIndexChanged += new System.EventHandler(this.lv_teainfo_SelectedIndexChanged);
            // 
            // columnHeader1
            // 
            this.columnHeader1.Text = "编号";
            this.columnHeader1.Width = 50;
            // 
            // columnHeader2
            // 
            this.columnHeader2.Text = "饮品名称";
            this.columnHeader2.Width = 76;
            // 
            // columnHeader3
            // 
            this.columnHeader3.Text = "价格（小）";
            this.columnHeader3.Width = 87;
            // 
            // columnHeader4
            // 
            this.columnHeader4.Text = "价格（中）";
            this.columnHeader4.Width = 89;
            // 
            // columnHeader5
            // 
            this.columnHeader5.Text = "价格（大）";
            this.columnHeader5.Width = 94;
            // 
            // columnHeader6
            // 
            this.columnHeader6.Text = "状态";
            this.columnHeader6.Width = 53;
            // 
            // columnHeader7
            // 
            this.columnHeader7.Text = "图片地址";
            this.columnHeader7.Width = 97;
            // 
            // btn_delete
            // 
            this.btn_delete.Location = new System.Drawing.Point(456, 0);
            this.btn_delete.Name = "btn_delete";
            this.btn_delete.Size = new System.Drawing.Size(75, 39);
            this.btn_delete.TabIndex = 3;
            this.btn_delete.Text = "删除";
            this.btn_delete.UseVisualStyleBackColor = true;
            this.btn_delete.Click += new System.EventHandler(this.button5_Click);
            // 
            // btn_stopsale
            // 
            this.btn_stopsale.Location = new System.Drawing.Point(349, 0);
            this.btn_stopsale.Name = "btn_stopsale";
            this.btn_stopsale.Size = new System.Drawing.Size(75, 39);
            this.btn_stopsale.TabIndex = 2;
            this.btn_stopsale.Text = "停售";
            this.btn_stopsale.UseVisualStyleBackColor = true;
            this.btn_stopsale.Click += new System.EventHandler(this.button4_Click);
            // 
            // btn_saleout
            // 
            this.btn_saleout.Location = new System.Drawing.Point(246, 0);
            this.btn_saleout.Name = "btn_saleout";
            this.btn_saleout.Size = new System.Drawing.Size(75, 39);
            this.btn_saleout.TabIndex = 1;
            this.btn_saleout.Text = "售完";
            this.btn_saleout.UseVisualStyleBackColor = true;
            this.btn_saleout.Click += new System.EventHandler(this.button3_Click);
            // 
            // btn_onsale
            // 
            this.btn_onsale.Location = new System.Drawing.Point(141, 0);
            this.btn_onsale.Name = "btn_onsale";
            this.btn_onsale.Size = new System.Drawing.Size(75, 39);
            this.btn_onsale.TabIndex = 0;
            this.btn_onsale.Text = "在售";
            this.btn_onsale.UseVisualStyleBackColor = true;
            this.btn_onsale.Click += new System.EventHandler(this.button1_Click);
            // 
            // lbl_note
            // 
            this.lbl_note.AutoSize = true;
            this.lbl_note.Location = new System.Drawing.Point(346, 285);
            this.lbl_note.Name = "lbl_note";
            this.lbl_note.Size = new System.Drawing.Size(0, 15);
            this.lbl_note.TabIndex = 15;
            this.lbl_note.Click += new System.EventHandler(this.label7_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(6, 72);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(218, 124);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // Frm_TeaInfoManage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 667);
            this.Controls.Add(this.lbl_note);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Frm_TeaInfoManage";
            this.Text = "饮品信息列表";
            this.Load += new System.EventHandler(this.Frm_TeaInfoManage_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txt_tea_name;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txt_tea_price_max;
        private System.Windows.Forms.TextBox txt_tea_price_mid;
        private System.Windows.Forms.TextBox txt_tea_price_min;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox cbx_status;
        private System.Windows.Forms.Button btn_reset;
        private System.Windows.Forms.Button btn_save;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Button btn_select_image;
        private System.Windows.Forms.ListView lv_teainfo;
        private System.Windows.Forms.Button btn_delete;
        private System.Windows.Forms.Button btn_stopsale;
        private System.Windows.Forms.Button btn_saleout;
        private System.Windows.Forms.Button btn_onsale;
        private System.Windows.Forms.ColumnHeader columnHeader1;
        private System.Windows.Forms.ColumnHeader columnHeader2;
        private System.Windows.Forms.ColumnHeader columnHeader3;
        private System.Windows.Forms.ColumnHeader columnHeader4;
        private System.Windows.Forms.ColumnHeader columnHeader5;
        private System.Windows.Forms.ColumnHeader columnHeader6;
        private System.Windows.Forms.ColumnHeader columnHeader7;
        private System.Windows.Forms.Label lbl_status;
        private System.Windows.Forms.Label lbl_note;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
    }
}