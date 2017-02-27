using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


namespace AuctionSystem {
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            
        }

        protected void ButtonLogin_Click(object sender, EventArgs e)
        {            
            string userName = loginControl.UserName;
            string password = loginControl.Password;
            if (userName.Equals("") || password.Equals(""))
            {
                LabelLoginError.Visible = true;
                LabelLoginError.Text = "Please enter username & password";
            }
            else
            {                
                SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
                string query = "SELECT[userRole] FROM[User] WHERE [userName] = @user AND [userPassword] = @pwd;";                
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.Add("@user", System.Data.SqlDbType.VarChar, 50).Value = userName;
                cmd.Parameters.Add("@pwd", System.Data.SqlDbType.VarChar, 50).Value = password;
                conn.Open();
                SqlDataReader dr = cmd.ExecuteReader();
                if (dr.Read())
                {
                    Session["username"] = userName;
                    string role = dr.GetFieldValue<string>(0);
                    switch (role)
                    {
                        case "Admin":
                            Response.Redirect("~/AdminHome.aspx");
                            break;
                        case "Bidder":
                            Response.Redirect("~/BidderHome.aspx");
                            break;
                        case "Seller":
                            Response.Redirect("~/SellerHome.aspx");
                            break;
                        default:
                            Response.Redirect("~/Home.aspx");
                            break;
                    }
                }
                else {
                    LabelLoginError.Visible = true;
                    LabelLoginError.Text = "Authentication Failure";
                }
                dr.Close();
                conn.Close();               
            }
        }
        protected void ButtonHome_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Home.aspx");
        }
        protected void ButtonRegister_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Registration.aspx");
        }
    }
}
