using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;    
using System.Threading.Tasks;

namespace test_12._8_饮品店点餐收银系统_
{
    
    public partial class DatawWork : Component
    {
        static string connstr = ConfigurationManager.AppSettings["DBConn"];
        /// <summary>
        /// 
        /// </summary>
        ///

        public static DataTable DataQuery(string str)
        {
            SqlConnection conn = new SqlConnection(connstr);
            conn.Open();
            SqlDataAdapter da = new SqlDataAdapter(str, conn);
            DataTable dt = new DataTable();
            da.Fill(dt);
            conn.Close();
            return dt;
        }
        public static int DataExcute(string str)
        {
            SqlConnection conn = new SqlConnection(connstr);
            conn.Open();
            SqlCommand cmd = new SqlCommand(str, conn);
            int i = cmd.ExecuteNonQuery();
            conn.Close();
            return i;
        }

        public static int ExecuteScalar(string str)
        {
            SqlConnection conn = new SqlConnection(connstr);
            conn.Open();
            SqlCommand cmd = new SqlCommand(str, conn);
            int i = int.Parse(cmd.ExecuteScalar().ToString());
            conn.Close();
            return i;
        }

        public DatawWork()
        {
            InitializeComponent();
        }

        public DatawWork(IContainer container)
        {
            container.Add(this);

            InitializeComponent();
        }
    }
}
