using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Duyuru
    {
        [Key]
        public int ID { get; set; }
        public byte[] DuyuruFoto { get; set; }
        public string DuyuruBaslik { get; set; }
        public string DuyuruIcerik { get; set; }
        public Nullable<System.DateTime> DuyuruTarih { get; set; }
        public Nullable<System.DateTime> Tarih { get; set; }
    }
}