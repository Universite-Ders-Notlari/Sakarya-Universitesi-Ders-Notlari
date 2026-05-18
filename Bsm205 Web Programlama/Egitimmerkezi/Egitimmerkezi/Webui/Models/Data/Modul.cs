using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Modul
    {
        [Key]
        public int ID { get; set; }
        public byte[] ModulFoto { get; set; }
        public string ModulBaslik { get; set; }
        public string ModulIcerik { get; set; }
        public Nullable<System.DateTime> Tarih { get; set; }
    }
}