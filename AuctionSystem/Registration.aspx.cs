using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;

namespace AuctionSystem {
    public partial class Registration : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            LabelErrorMessage.Visible = false;
            LabelUserAdded.Visible = false;
        }
        protected void ButtonRegister_Click(object sender, EventArgs e)
        {
            string userName = TextBoxUsername.Text;
            string email = TextBoxEmail.Text;
            string password = TextBoxPassword.Text;
            string confirmPassword = TextBoxConfirmPassword.Text;
            string role = DropDownListCategory.SelectedValue;

            if (userName.Equals("") || password.Equals("'") || confirmPassword.Equals(""))
            {
                LabelErrorMessage.Visible = true;
                LabelErrorMessage.Text = "Please enter the required fields marked with asterisk(*)";
            }
            else if (!password.Equals(confirmPassword))
            {
                LabelErrorMessage.Visible = true;
                LabelErrorMessage.Text = "Password mismatch..Please try again";
            }
            else
            {
                SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["ConnectionString"].ConnectionString);
                string query = "INSERT INTO [User] ([userName],[userPassword],[userRole])values (@user,@pwd,@role);";                
                SqlCommand cmd = new SqlCommand(query, conn);
                cmd.Parameters.Add("@user", System.Data.SqlDbType.VarChar, 50).Value = userName;
                cmd.Parameters.Add("@pwd", System.Data.SqlDbType.VarChar, 50).Value = password;
                cmd.Parameters.Add("@role", System.Data.SqlDbType.VarChar, 50).Value = role;
                conn.Open();
                int  modified = (int)cmd.ExecuteNonQuery();
                if (modified>0)
                {
                    LabelUserAdded.Visible = true;
                    LabelUserAdded.Text = userName + " Added Successfully";
                }
                else
                {
                    LabelErrorMessage.Visible = true;
                    LabelErrorMessage.Text = "Unable to Add User: "+userName;
                }

            }
        }

        protected void ButtonHome_Click(object sender, EventArgs e)
        {
            Response.Redirect("~/Home.aspx");
        }
    }
}

