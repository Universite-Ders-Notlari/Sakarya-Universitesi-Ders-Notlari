using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace WebUI.Models.Data
{
    public class Oneri
    {
        [Key]
        public int ID { get; set; }
        public string AdSoyad { get; set; }
        public string Telefon { get; set; }
        public string Eposta { get; set; }
        public string Mesaj { get; set; }
        public Nullable<System.DateTime> Tarih { get; set; }
    }
}